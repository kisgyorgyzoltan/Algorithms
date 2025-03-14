import random

n = 10000

f = open("2149_4_1_2.in", "w")
f.write(str(n) + "\n")
for i in range(n):
    f.write(str(random.randint(1, 1000000)) + "\n")
