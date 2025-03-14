import random


def test():
    f = open("2149_8_3_3.in", "w")
    n = random.randint(1, 1_000_000)
    f.write(f"{n}\n")
    for i in range(n):
        f.write(f"{random.randint(1, 9)} {random.randint(1, 9)} \n")
    f.close()


test()
