import names
import random

allNames = []
n = 100
filename = "2149_2_7_3.in"


def main():
    f = open(filename, "w")
    f.truncate(0)

    dbcsoport = 1  # random.randint(1, 10)
    f.write(str(dbcsoport) + "\n")

    for i in range(dbcsoport):
        dbdiak = random.randint(1, 10)
        f.write(str(dbdiak) + "\n")
        for j in range(dbdiak):
            fullName = names.get_full_name()
            while fullName in allNames:
                fullName = names.get_full_name()
            allNames.append(fullName)
            f.write(str(len(fullName)) + "\n")
            f.write(fullName + "\n")

    f.close()


main()
