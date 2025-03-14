import random

f = open("2149_6_6_3.in", "w")
n = 1
f.write(str(n) + "\n")

maxnap = 100

for i in range(n):
    start = random.randint(1, maxnap)
    end = random.randint(start + 1, maxnap)
    f.write(str(start) + " " + str(end) + "\n")
for i in range(n):
    event = random.randint(1, maxnap)
    f.write(str(event) + "\n")
f.close()
