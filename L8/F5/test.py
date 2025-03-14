import random


def test():
    f = open("2149_8_5_3.in", "w")
    n = random.randint(1, 1000)
    m = random.randint(1, 1000)

    f.write(f"{n} \n")
    for i in range(n):
        f.write(f"{random.randint(0, 1_000_000)} ")
    f.write("\n")
    f.write(f"{m} \n")
    for j in range(m):
        f.write(f"{random.randint(0, 1_000_000)} ")
    f.close()


test()
