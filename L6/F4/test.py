import random

f = open("2149_6_4_1.in", "w")
n = random.randint(0, 1000000000)
m = random.randint(0, 10000)
f.write(str(n) + " " + str(m) + "\n")
for i in range(m):
    l = random.randint(0, 10000)
    r = random.randint(l + 1, 10000)
    f.write(str(l) + " " + str(r) + "\n")
