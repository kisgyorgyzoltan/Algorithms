no = int(input("Enter Number of disks "))


def move_tower(n, fr, to, mid):
    if (n >= 1) and (fr != 2) and (to != 2):
        move_tower(n - 1, fr, to, mid)
        print("Moving disk ", n, "from ", fr, " to ", mid)
        move_tower(n - 1, to, fr, mid)
        print("Moving disk ", n, "from ", mid, " to ", to)
        move_tower(n - 1, fr, to, mid)
    elif (n >= 1) and ((fr == 2) or (to == 2)):
        move_tower(n - 1, fr, mid, to)
        print("Moving disk ", n, "from ", fr, " to ", to)
        move_tower(n - 1, mid, to, fr)


# move_tower(no,1,2,3)
move_tower(no, 1, 3, 2)
