import random


def create():
    f = open("2149_7_2_3.in", "w")
    # n = random.randint(1, 100_000)
    # k = random.randint(1, n)
    n = 100
    k = 50
    f.write(f"{n} {k}\n")
    for i in range(n):
        # f.write(f"{float(n - i)} ")
        # random double values
        value = random.uniform(0, 100)
        f.write(f"{value:.2f}\n")
    f.close()


create()
