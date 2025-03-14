import subprocess
import random

db = [
    # (1, 1),
    # (2, 0),
    # (3, 0),
    # (4, 2),
    (5, 10),
    # (6, 4),
    (7, 40),
    (8, 92),
    (9, 352),
    (10, 724),
    (11, 2680),
    (12, 14200),
    (13, 73712),
    (14, 365596),
]

error = False
for it in range(1000):
    for pair in db:
        n, expected = pair
        f = open("input.txt", "w")
        sampleSize = 5
        f.write(f"{n} {sampleSize} \n")
        indexes = [i for i in range(1, expected + 1)]
        random.shuffle(indexes)
        indexes = random.sample(indexes, sampleSize)
        for i in indexes:
            f.write(f"{i} ")
        f.close()
        subprocess.run(["./regi.exe < input.txt > outRegi.txt"], shell=True)
        subprocess.run(["./uj.exe < input.txt > outUj.txt"], shell=True)

        f1 = open("outRegi.txt", "r")
        f2 = open("outUj.txt", "r")
        if f1.read() != f2.read():
            print(f"Failed for n = {n}")
            error = True
            break
    if error:
        break
