import random

f = open("2149_6_7_3.in", "w")
# n = random.randint(0, 10_000)
n = 10
f.write(str(n) + "\n")
for i in range(n):
    profit = random.randint(1, 10_000)
    deadline = random.randint(1, 10_000)
    f.write(str(profit) + " " + str(deadline) + "\n")
f.close()
