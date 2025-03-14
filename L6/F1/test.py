import random

int32max = 2147483647


def create():
    f = open("2149_6_1_3.in", "w")
    # n = random.randint(1, 500)
    n = 500
    # m = random.randint(1, 500)
    m = 500
    f.write(str(n) + " " + str(m) + "\n")
    for i in range(n):
        for j in range(m):
            f.write(str(random.randint(0, int32max)) + " ")
        f.write("\n")
    f.close()


create()
