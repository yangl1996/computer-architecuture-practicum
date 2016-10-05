def matmult(a,b):
    zip_b = zip(*b)
    # uncomment next line if python 3 : 
    # zip_b = list(zip_b)
    return [[sum(ele_a*ele_b for ele_a, ele_b in zip(row_a, col_b)) 
             for col_b in zip_b] for row_a in a]

f = open("input.txt", 'r')

m1 = []
m2 = []

for i in range(1000):
	inter = []
	for j in range(1000):
		inter.append(int(f.readline()))
	m1.append(inter)
m2 = m1
matmult(m1, m2)
