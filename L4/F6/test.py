import random
import subprocess


def create():
    f = open("2149_4_6_3.in", "w")
    f.write("0\n")


def test():
    create()
    exe = ["x64/Debug/F6.exe"]
    subprocess.run(exe, stdin=open("2149_4_6_3.in"), stdout=open("2149_4_6_3.out", "w"))


test()
