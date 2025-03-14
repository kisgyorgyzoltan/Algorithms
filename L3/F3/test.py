import random
import subprocess

n = 100


# Function to convert an integer to a Roman numeral
def int_to_roman(n):
    val = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    syms = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
    roman_numeral = ""
    i = 0
    while n > 0:
        for _ in range(n // val[i]):
            roman_numeral += syms[i]
            n -= val[i]
        i += 1
    return roman_numeral


for i in range(n):
    number = random.randint(1, 3999)
    filename = "be.in"
    roman = int_to_roman(number)
    f = open(filename, "w")
    f.truncate(0)
    f.write(str(roman))
    f.close()

    # Run the program
    cpp_exe = "F3.exe"
    command = [cpp_exe]
    subprocess.run(command, universal_newlines=True)
    f = open("ki.out", "r")
    result = f.read()
    f.close()

    myres = f"A megadott szam arab szamjegyekkel: {number}"
    if result != myres:
        print(f"Test failed for {roman}. roman: {result}, actual: {number}")
    else:
        print(f"Test nr {i + 1} passed")
