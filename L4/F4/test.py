import random
import subprocess


def create():
    n = 1000000
    f = open("2149_4_4_3.in", "w")
    f.write(str(n) + "\n")
    for i in range(n):
        # f.write(str(random.randint(1, 1000000)) + "\n")
        f.write(str(n - i) + "\n")


def test():
    create()
    exe = ["x64/Debug/F4.exe"]
    subprocess.run(exe, stdin=open("2149_4_4_3.in"), stdout=open("2149_4_4_3.out", "w"))


test()
