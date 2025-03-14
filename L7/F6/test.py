import random


def test():
    f = open("2149_7_6_3.in", "w")
    # n = random.randint(1, 100_000)
    n = 10
    x = random.randint(1, 100_000_000)
    f.write(str(n) + " " + str(x) + "\n")
    num = 0
    for i in range(n - 1):
        num = random.randint(1, 100_000_000)
        f.write(str(num) + " ")
    f.write(str(x - num))
    f.close()


test()
