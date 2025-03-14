import subprocess
import random

exe = "x64/Debug/F9.exe"

ullongmax = 18446744073709551615


def create():
    f = open("2149_4_9_3.in", "w")
    n1 = random.randint(1, ullongmax)
    n2 = random.randint(1, ullongmax)
    f.write(str(10) + " " + str(10) + "\n")
    f.close()


def test():
    create()
    subprocess.run(
        [exe], stdin=open("2149_4_9_3.in", "r"), stdout=open("2149_4_9_3.out", "w")
    )


test()
