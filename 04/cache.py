import math
import random

class CacheLine:
    def __init__(self):
        self.tag = 0
        self.dirty = False
        self.valid = False
        self.address = 0
        self.last_access = 0
        self.fill_in_time = 0
        self.access_count = 0
        self.prefetchtag = 0


class CacheSet:
    def __init__(self, set_width):
        self.lines = []
        self.width = set_width
        self.clock = 0
        self.filled_lines_number = 0
        for i in range(set_width):
            self.lines.append(CacheLine())

    def update_access_time(self, index):
        """
        Update last access time
        """
        self.clock += 1
        self.lines[index].last_access = self.clock

    def update_access_count(self, index, hit):
        """
        Update last access access count
        """
        if hit == True:
            self.lines[index].access_count += 1
        else:
            self.lines[index].access_count = 1

    def update_fill_in_time(self, index):
        """
        Update fill in time
        """
        #New lines are fetched in because of cold miss
        if self.filled_lines_number < self.width:
            self.filled_lines_number += 1
            self.lines[index].fill_in_time = self.filled_lines_number
        #The cache is full
        else:
            self.fill_in_time = self.width

    def lookup(self, tag):
        """
        Find the tag in set
        """
        for i in range(self.width):
            if self.lines[i].tag == tag and self.lines[i].valid:
                return i
        return None

    def find_empty(self):
        """
        Look for empty (invalid) slot
        """
        for i in range(self.width):
            if self.lines[i].valid is False:
                return i
        return None

    def find_lru(self):
        """
        Find the LRU line
        """
        lru_clock = self.lines[0].last_access
        lru_index = 0
        for i in range(self.width):
            if self.lines[i].last_access < lru_clock:
                lru_clock = self.lines[i].last_access
                lru_index = i
        return i

    def find_random(self):
        """
        Find the Random line
        """
        i = random.randint(0,self.width-1)
        return i

    def find_fifo(self):
        """
        Find the FIFO line
        """
        #Select the earliest one, every line's rank need to forward one
        for i in range(self.width):
            self.lines[i].fill_in_time -= 1
        fifo_time = self.lines[0].fill_in_time
        fifo_index = 0
        for i in range(self.width):
            if self.lines[i].fill_in_time < fifo_time:
                fifo_time = self.lines[i].fill_in_time
                fifo_index = i
        return i

    def find_lfu(self):
        """
        Find the LFU line
        """
        lfu_cnt = self.lines[0].access_count
        lfu_index = 0
        for i in range(self.width):
            if self.lines[i].access_count < lfu_cnt:
                lfu_cnt = self.lines[i].access_count
                lfu_index = i
        return i

    def update_line(self, index, tag, address):
        """
        Update content of a line
        """
        self.lines[index].tag = tag
        self.lines[index].address = address
        self.lines[index].dirty = False
        self.lines[index].valid = True

    def check_dirty(self, index):
        """
        Check whether a line is dirty
        """
        return self.lines[index].dirty
    
    def mark_dirty(self, index):
        """
        Mark a line as dirty
        """
        self.lines[index].dirty = True

class Cache:
    """ Cache simulator """
    
    def __init__(self, name, size, block_size, set_width, replacement, prefetching, write_hit, write_miss, bus_latency, hit_latency, access_latency, memory_latency, bypass, next_level=None):
        # sanity checks
        assert size % block_size is 0
        self.block_count = size // block_size    # number of lines
        assert self.block_count % set_width is 0
        self.set_count = self.block_count // set_width # number of sets
        assert block_size >= 8
        assert replacement in ["LRU", "Random","FIFO","LFU"]
        assert prefetching in ["Never", "Always", "Miss","Tagged"]
        assert write_hit in ["WT", "WB"]
        assert write_miss in ["WA", "NA"]
        assert bypass in [True, False]
        assert math.log2(block_size).is_integer()
        assert math.log2(self.set_count).is_integer()
        self.set_count_log = int(math.log2(self.set_count))
        self.block_size_log = int(math.log2(block_size))

        # cache counter
        self.access_counter = 0         # access to this level
        self.next_level_counter = 0     # access to next level
        self.miss_counter = 0           # miss at this level
        self.replacement_counter = 0    # replacement at this level
        self.prefetchhit = 0
        self.cold_miss_cnt = 0

        # construct cache
        self.name = name
        self.size = size                        # cache size
        self.block_size = block_size            # size of a block
        self.set_width = set_width              # how many blocks in a set
        self.replacement = replacement          # replacement policy
        self.prefetching = prefetching          # prefetching policy
        self.write_hit = write_hit              # write hit policy
        self.write_miss = write_miss            # write miss policy
        self.bus_latency = bus_latency          # bus latency
        self.hit_latency = hit_latency          # hit latency
        self.access_latency = access_latency    # access latency
        self.memory_latency = memory_latency    # main memory latency
        self.next_level = next_level            # next level cache
        self.bypass = bypass                    # bypass this cache
        
        self.sets = []
        for i in range(self.set_count):
            self.sets.append(CacheSet(self.set_width))

        self.bypass_status = []
        for i in range(1024):
            self.bypass_status.append({"miss_count": 0, "access_count": 0})

    def determine_bypass(self, address):
        # optimal bypass threshold 1 - hit_latency / next_latency
        add = address >> 54 # get highest 10 bits
        status = self.bypass_status[add]
        if status['access_count'] < 100:
            return False
        miss_rate = float(status['miss_count']) / float(status['access_count'])
        if miss_rate > 0.5:
            return True
        else:
            return False

    def bypass_record(self, address, miss):
        add = address >> 54
        self.bypass_status[add]['access_count'] += 1
        if miss is True:
            self.bypass_status[add]['miss_count'] += 1

    def read_from_next(self, address, prefetchFlag):

        """
        Read from the next level
        """
        if self.next_level is None:
            # next level is main memory
            return self.memory_latency
        else:
            # next level is another cache
            return self.next_level.read(address, prefetchFlag)

    def write_to_next(self, address):
        """
        Write to the next level
        """
        if self.next_level is None:
            return self.memory_latency
        else:
            return self.next_level.write(address)

    def write(self, address):
        """
        Write to this level
        """
        if self.determine_bypass(address) and self.bypass:
            self.access_counter += 1
            return self.write_to_next(address) + self.bus_latency
        # calculate set index and tag
        set_index = (address >> self.block_size_log) & (self.set_count - 1)
        tag = (address >> self.block_size_log) >> self.set_count_log
        target_set = self.sets[set_index]
        
        # test the tag
        tag_lookup_result = target_set.lookup(tag)
        self.access_counter += 1
        if self.prefetching == 'Always':
            self.read(address + 64, True)
            self.read(address + 64*2, True)
            self.read(address + 64*3, True)
        if tag_lookup_result is not None:
            # write HIT
            self.bypass_record(address, False)
            if self.write_hit == "WT":
                # write THROUGH
                # write to all levels
                # just call write_to_next as it does the job recursively
                return self.write_to_next(address)
            elif self.write_hit == "WB":
                # write BACK
                # only write to current level and mark dirty
                target_set.mark_dirty(tag_lookup_result)
                target_set.update_access_time(tag_lookup_result)
                #update access count
                target_set.update_access_count(tag_lookup_result,True)
                if target_set.lines[tag_lookup_result].prefetchtag == 1:
                    self.prefetchhit += 1
                    if self.prefetching =='Tagged':
                        self.read(address + 64, True)
                        #self.read(address + 64*2, True)
                        #self.read(address + 64*3, True)
                return self.access_latency
        else:
            # write MISS
            self.bypass_record(address, True)
            self.miss_counter += 1
            if self.write_miss == "WA":
                # write ALLOCATE
                # just use read() to load the block and retry
                tot_latency = self.read(address, False) - self.access_latency
                # use read() to allocate the block, no real read operation
                # intended, so remove one
                self.miss_counter -= 1
                self.access_counter -= 1
                # use write() to resume write operation after allocating,
                # there's still only one write operation ongoing        
                tot_latency += self.write(address)
                #set the access count to 1
                tag_lookup_result = target_set.lookup(tag)
                target_set.update_access_count(tag_lookup_result, False)
                return tot_latency
            elif self.write_miss == "NA":
                # write NO-ALLOCATE
                # do nothing to the whole cache, write direct into memory
                return self.memory_latency



    def read(self, address,prefetchFlag):

        """
        Read from this level
        Returns the latency
        """
        if self.determine_bypass(address) and self.bypass:
            self.access_counter += 1
            return self.read_from_next(address, prefetchFlag) + self.bus_latency
        # equalvalent of HandleRequest in template
        # get set index and tag
        # tag | set_index | offset
        set_index = (address >> self.block_size_log) & (self.set_count - 1)
        tag = (address >> self.block_size_log) >> self.set_count_log
        target_set = self.sets[set_index]
        
        # test the tag
        tag_lookup_result = target_set.lookup(tag)
        if prefetchFlag == False:
            self.access_counter += 1

        if self.prefetching == 'Always' and prefetchFlag == False:
            self.read(address+64, True)
            self.read(address + 64*2, True)
            self.read(address + 64*3, True)
        if tag_lookup_result is not None:
            # cache HIT
            # update last used time
            self.bypass_record(address, False)
            target_set.update_access_time(tag_lookup_result)
            #update access count(hit)
            target_set.update_access_count(tag_lookup_result,True)
            #update fetchtag
            if prefetchFlag == False and target_set.lines[tag_lookup_result].prefetchtag == 1:
                self.prefetchhit += 1
                if self.prefetching == 'Tagged':
                    self.read(address + 64, True)
                    #self.read(address + 64*2, True)
                    #self.read(address + 64*3, True)
            return self.access_latency
        else:
            # cache MISS
            self.bypass_record(address, True)
            if prefetchFlag == False:
                self.miss_counter += 1
            # check for empty slot
            empty_find_result = target_set.find_empty()
            fetch_destination = None
            next_level_latency = 0
            # make room for new item
            if empty_find_result is not None:
                # empty slot available
                # new data will reside in the empty slot
                self.cold_miss_cnt += 1
                fetch_destination = empty_find_result
            else:
                # no empty slot, have to replace
                self.replacement_counter += 1

                replacement_policy = {'LRU':target_set.find_lru(),
                                      'Random':target_set.find_random(),
                                      'FIFO':target_set.find_fifo(),
                                      'LFU':target_set.find_lfu()}
                fetch_destination = replacement_policy[self.replacement]

                if target_set.check_dirty(fetch_destination) is True:
                    # destination is dirty, write back before replacing
                    self.next_level_counter += 1
                    next_level_latency += self.write_to_next(target_set.lines[fetch_destination].address)
            self.next_level_counter += 1
            next_level_latency += self.read_from_next(address,prefetchFlag)
            target_set.update_line(fetch_destination, tag, address)
            # update last access time
            target_set.update_access_time(fetch_destination)
            # update fill in time
            target_set.update_fill_in_time(fetch_destination)
            #update access count(miss)
            target_set.update_access_count(fetch_destination,False)
            #update fetchtag
            if prefetchFlag == True:
                target_set.lines[fetch_destination].prefetchtag = 1
            else:
                target_set.lines[fetch_destination].prefetchtag = 0
            if self.prefetching == 'Miss' and prefetchFlag == False:
                self.read(address + 64, True)
                self.read(address + 64*2, True)
                self.read(address + 64*3, True)
            if self.prefetching == 'Tagged' and prefetchFlag == False:
                self.read(address + 64, True)
                #self.read(address + 64*2, True)
                #self.read(address + 64*3, True)
            return self.access_latency + next_level_latency
