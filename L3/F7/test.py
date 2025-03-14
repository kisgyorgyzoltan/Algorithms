import random
import subprocess
import sys

sys.set_int_max_str_digits(10000000)

twoNumbers = []


def createTest():
    f = open("2149_3_7_2.in", "w")
    for i in range(2):
        n = random.randint(1, 100000)
        f.write(str(n) + "\n")
        numbers = ""
        for j in range(n):
            numbers += str(random.randint(1, 9))
        f.write(numbers + "\n")
        twoNumbers.append(int(numbers))
    f.close()


def test():
    createTest()
    subprocess.run(["F7_file.exe"])
    f = open("2149_3_7_1.out", "r")
    myresult = f.read()
    f.close()
    pythonresult = str(twoNumbers[0] + twoNumbers[1])

    if myresult == pythonresult:
        print("Correct")
        return True
    else:
        print("Incorrect")
        print("My result: " + myresult)
        print("Python result: " + pythonresult)
        return False


createTest()
