import random

f = open("2149_6_8_3.in", "w")
# n = random.randint(1, 500_000)
n = 10000
for i in range(n):
    choice = random.randint(1, 2)
    if choice == 1:
        f.write("b")
    else:
        f.write("j")
f.close()
