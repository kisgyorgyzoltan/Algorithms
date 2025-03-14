import random

max = 100000000000000


def create():
    f = open("2149_5_1_1.in", "w")
    # n = random.randint(3, 1000)
    n = 1
    f.write(str(n) + "\n")
    for i in range(n):
        f.write(str(random.randint(max - 1000, max)) + "\n")
    f.close()


create()
