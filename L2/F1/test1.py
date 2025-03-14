import names
import random
import subprocess

allNames = []
diakok = {}
n = 5
filename = "be.in"
numberOfTests = 10
randomName = ""


def createTest():
    f = open(filename, "w")
    f.truncate(0)

    f.write(str(n) + "\n")

    for i in range(n):
        fullName = names.get_full_name()
        while fullName in allNames:
            fullName = names.get_full_name()

        fullName = fullName.split()
        fullName = fullName[1] + " " + fullName[0]
        allNames.append(fullName)

        lenName = len(fullName)

        chance = 0.05
        randomBest = random.uniform(0, 1)
        if randomBest <= chance:
            randomFloat = 10.00
        else:
            randomFloat = random.uniform(1, 10)

        f.write(str(lenName) + "\n")
        f.write(fullName + "\n")
        f.write("{:.2f}".format(randomFloat) + "\n")
        diakok.update({fullName: randomFloat})

    randomName = allNames[random.randint(0, len(allNames) - 1)]
    f.write(str(len(randomName)) + "\n")
    f.write(randomName)
    f.close()


def pythonCalc():
    # sort diakok by value tuple second element
    global diakok, randomNamec
    diakok = sorted(diakok.items(), key=lambda x: x[1], reverse=True)
    max1 = diakok[0][1]
    max1Diak = list(filter(lambda x: x[1] == max1, diakok))
    max2Diak = []
    max3Diak = []
    diakok = list(filter(lambda x: x[1] != max1, diakok))
    if len(diakok) > 0:
        max2 = diakok[0][1]
        max2Diak = list(filter(lambda x: x[1] == max2, diakok))
        diakok = list(filter(lambda x: x[1] != max2, diakok))
        if len(diakok) > 0:
            max3 = diakok[0][1]
            max3Diak = list(filter(lambda x: x[1] == max3, diakok))

    if randomName in max1Diak:
        return "igen"
    elif randomName in max2Diak and len(max2Diak) <= 2:
        return "igen"
    elif randomName in max3Diak and len(max3Diak) <= 2:
        return "igen"
    else:
        return "nem"


for i in range(numberOfTests):
    # createTest()
    print("Testing...")
    pythonResult = pythonCalc()
    cpp_exe = "F1.exe"
    # run F1.exe
    command = [cpp_exe]
    subprocess.run(command, universal_newlines=True)
    f = open("ki.out", "r")
    cppResult = f.read()
    f.close()

    if pythonResult.strip() != cppResult:
        print(f"{i}: Test failed. Expected:", pythonResult, "Actual:", cppResult)
        # print("Input:", allNames)
        break
    else:
        print(f"{i}: Test passed.")
