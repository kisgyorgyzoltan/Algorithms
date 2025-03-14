import random


def create():
    n = 4
    lista = list(range(0, n + 1))
    print(lista)
    random.shuffle(lista)
    f = open("2149_6_5_3.in", "w")
    f.write(str(n) + "\n")
    for i in lista:
        f.write(str(i) + " ")
    f.close()


create()
