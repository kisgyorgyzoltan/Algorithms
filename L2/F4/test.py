import random

n = 500000
f = open("2149_2_4_3.in", "w")
f.write(str(n) + "\n")
for i in range(n):
    f.write(str(random.randint(0, 100000)) + " ")
