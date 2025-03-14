import random

f = open("2149_6_9_3.in", "w")
m = random.randint(1, 10000)
n = random.randint(m, 10000)
f.write(str(m))
for i in range(m):
    f.write(str(random.randint(-10000, 10000)) + " ")
f.write("\n")
f.write(str(n))
for i in range(n):
    f.write(str(random.randint(-10000, 10000)) + " ")
f.write("\n")
f.close()
