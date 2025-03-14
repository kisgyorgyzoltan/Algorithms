import random


def create():
    f = open("2149_6_2_3.in", "w")
    n = 1
    f.write(str(n) + "\n")
    lista = []
    for i in range(n):
        szam = random.randint(-100, 100)
        lista.append(szam)
    lista[0] = 0
    lista[0] = -sum(lista)
    for i in lista:
        f.write(str(i) + " ")
    f.close()


create()
