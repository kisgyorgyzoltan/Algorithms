import subprocess
import random

exe = "x64/Release/F7.exe"


def create():
    f = open("2149_4_7_3.in", "w")
    # n = random.randint(1, 10000)
    # n = 0
    n = 10000
    f.write(str(n) + "\n")
    for i in range(0, n):
        f.write(str(random.randint(-10000, 10000)) + " ")
    x = random.uniform(-10000, 10000)
    f.write("\n" + str(x))


def test():
    create()
    subprocess.run(
        [exe], stdin=open("2149_4_7_3.in", "r"), stdout=open("2149_4_7_3.out", "w")
    )


# create()
test()
