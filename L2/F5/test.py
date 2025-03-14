import random

n = 40
f = open("2149_2_5_3.in", "w")
f.write(str(n) + "\n")
for i in range(n):
    f.write(str(random.randint(0, 1500)) + " ")
