# Usage

Requirement: `python3`

The program reads trace from `trace.txt` in the same directory.

To run the simulator, simple issue `python3 simulator.py`.

# Cache Configuration

```
cp config.json.sample config.json
vim config.json
```

Follow the sample below to configure the cache.

```
{
    "arch": [   
    // cache architecture, each cache level is an element here
    {
        "name": "L1",           // level name
        "cache-size": 0,        // cache size (bytes)
        "block-size": 0,        // block size (bytes)
        "set-associativity": 0, // number of blocks in a set
        "access-latency": 0     // cache access latency, will be applied to
                                // both hit and miss accesses
    }],
    "memory-latency": 0,
    "replacement": "LRU",       // replacement policy, fixed to LRU
    "write-hit": "WT",          // write hit policy, choose from
                                // W(rite)T(hrough) and W(rite)B(ack)
    "write-miss": "WA"          // write miss policy, choose from
                                // W(rite)A(llocate) and N(o)A(llocate)
}
```
