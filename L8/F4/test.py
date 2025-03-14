import random


def test():
    f = open("2149_8_4_3.in", "w")
    n = random.randint(1, 1000)
    m = random.randint(1, 1000)
    f.write(f"{n} {m} \n")
    for i in range(n):
        for j in range(m):
            f.write(f"{random.randint(0, 1)} ")
        f.write("\n")
    f.close()


test()
