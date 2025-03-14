import random


def test():
    f = open("2149_7_3_3.in", "w")
    # n = random.randint(1, 500_000)
    n = 100
    f.write(str(n) + "\n")
    for i in range(n):
        num = random.randint(1, 1_000_000_000)
        f.write(str(num) + " ")
    f.close()


test()
