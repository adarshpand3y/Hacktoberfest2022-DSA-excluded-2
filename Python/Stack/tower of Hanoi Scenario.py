#To write a python program for tower of Hanoi Scenario
def towerofhanoi(n,source,intermediate, destination):
    if n == 1:
        print("Move disk 1 from rod", source, "to rod", intermediate)
        return
    towerofhanoi(n-1, source, destination,intermediate)
    print("Move disk", n, "from rod", source, "to rod", intermediate)
    towerofhanoi(n-1, destination, intermediate, source)

n=int(input("Enter number of disks: "))
#A, C, B are name of rods
towerofhanoi(n, 'A', 'C', 'B')

