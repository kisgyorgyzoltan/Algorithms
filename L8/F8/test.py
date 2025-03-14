# Adott 𝑛 mátrix, melyeket össze lehet szorozni az adott sorrendben. Állapítsuk
# meg a szorzásukhoz szükséges skalárszorzatok minimális számát és egy optimális
# zárójelezést!
# Bemenet
# A bemenet első sorában a mátrixok 𝑛 száma található, majd a következő 𝑛
# sor mindegyikében egy-egy mátrix sorainak és oszlopainak száma

import random


def createInput():
    f = open("2149_8_8_3.in", "w")
    n = random.randint(3, 100)
    f.write(str(n) + "\n")
    rows = random.randint(1, 1000)
    f.write(str(rows) + " ")
    collumns = random.randint(1, 1000)
    f.write(str(collumns) + "\n")
    for i in range(n - 1):
        rows = collumns
        f.write(str(rows) + " ")
        collumns = random.randint(1, 1000)
        f.write(str(collumns) + "\n")
    f.close()


createInput()
