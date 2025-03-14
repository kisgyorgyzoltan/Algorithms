import subprocess
import random

exe = "x64/Debug/F8.exe"


def create():
    f = open("2149_4_8_3.in", "w")
    # generate random hex number
    n = random.randint(1, 16)
    randomHex = lambda n: "".join([random.choice("0123456789ABCDEF") for i in range(n)])
    f.write(str(n) + "\n")
    randomHex = randomHex(n)
    f.write(randomHex)
    f.close()


def test():
    create()
    subprocess.run(
        [exe], stdin=open("2149_4_8_3.in", "r"), stdout=open("2149_4_8_3.out", "w")
    )


test()
