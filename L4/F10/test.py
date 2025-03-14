import subprocess
import random

exe = "x64/Debug/F10.exe"

ullongmax = 18446744073709551615


def create():
    f = open("2149_4_10_3.in", "w")
    # n1 = random.randint(1, ullongmax)
    n1 = ullongmax
    f.write(str(n1) + "\n")
    f.close()


def test():
    create()
    subprocess.run(
        [exe], stdin=open("2149_4_10_3.in", "r"), stdout=open("2149_4_10_3.out", "w")
    )


test()
