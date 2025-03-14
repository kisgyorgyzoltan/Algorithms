import random
import subprocess

exe = "./x64/Debug/F5.exe"  # "F5.exe"


def create():
    n = 10000
    f = open("2149_4_5_3.in", "w")
    f.write(str(n) + "\n")
    for i in range(n):
        # randomNum = random.randint(1, 1000000)
        randomNum = 1000000 - i

        f.write(str(randomNum) + "\n")
    f.close()


def test():
    create()
    # numbers = []
    # f = open("2149_4_5_3.in", "r")
    # lines = f.readlines()
    # lines = [line.rstrip("\n") for line in lines[1:]]
    # for line in lines:
    #     numbers.append(int(line))
    # f.close()

    subprocess.run(
        [exe], stdin=open("2149_4_5_3.in", "r"), stdout=open("2149_4_5_3.out", "w")
    )  # futtatom a programot

    # f = open("2149_4_5_3.out", "r")
    # lines = f.readlines()
    # lines = [int(line.rstrip("\n")) for line in lines[1:]]

    # f.close()


#     sortolva = sorted(numbers)
#     if (
#         lines != sortolva
#     ):  # összehasonlítom a pythonba beépített sorttal kapott eredményt a program által kiírttal
#         print("error")
#         print(f"lines {lines}")
#         print()
#         print(f"sortolva {sortolva}")
#         return False
#     else:
#         print("ok")
#         return True


# for i in range(10000):
#     if not test():
#         break
test()
