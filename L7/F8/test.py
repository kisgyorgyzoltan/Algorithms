import random


def test():
    f = open("2149_7_8_3.in", "w")
    n = random.randint(1, 9)
    f.write(str(n) + "\n")
    m = 2**n  # 2^n

    x = random.randint(1, m)
    y = random.randint(1, m)
    f.write(str(x) + " " + str(y) + "\n")
    f.close()


test()
