trace_file = open("2.trace")
t = set()
for line in trace_file:
    (op, add) = line.split()
    add = int(add,16)
    t.add(add)
print(len(t))