import subprocess


def fgv(x):
    dbosztok = {}
    for i in range(1, x + 1):
        dbosztok[i] = 0
        for j in range(2, i):
            if i % j == 0:
                dbosztok[i] += 1

    max = -1
    for i in dbosztok:
        if dbosztok[i] > max:
            max = dbosztok[i]

    for i in dbosztok:
        if dbosztok[i] == max:
            return (i, max)


for i in range(100, 1001):
    f = open("be.in", "w")
    f.truncate(0)
    f.write(str(i))
    f.close()
    subprocess.run(["F6.exe"])
    g = open("ki.out", "r")
    result = g.readline()
    g.close()
    szam, max = fgv(i)
    myresult = f"{szam} {max}"
    if result != myresult:
        print(f"hiba: expected:{result} real:{myresult}")
        break
