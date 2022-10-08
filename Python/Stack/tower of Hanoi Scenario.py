# (b) To write a python program for tower of Hanoi Scenario


def towerofhanoi(n, from_rod, to_rod, aux_rod):
    if n == 1:
        print("Move disk 1 from rod", from_rod, "to rod", to_rod)
        return
    towerofhanoi(n-1, from_rod, aux_rod, to_rod)
    print("Move disk", n, "from rod", from_rod, "to rod", to_rod)
    towerofhanoi(n-1, aux_rod, to_rod, from_rod)

n=int(input("Enter number of disks: "))
towerofhanoi(n, 'A', 'C', 'B')