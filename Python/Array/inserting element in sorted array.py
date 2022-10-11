def FindPos(AR,item):
    size=len(AR)
    if item <AR[0]:
        return 0
    else:
        pos=-1
    for i in range(size-1):
        if (AR[i]<=item and item < AR[i+1]):
            pos=i+1
            break
    if(pos == -1 and i<= size-1):
        pos = size
    return pos

def Shift(AR ,pos):
    AR.append(None)
    size=len(AR)

    i= size-1
    while i>=pos:
        AR[i]=AR[i-1]
        i-=1

# _main_
myList =[10,20,30,40,50,60,70]
print("The list in sorted order is")
print(myList)
ITEM=int(input("Enter new element to be inserted:"))
position =FindPos(myList,ITEM)
Shift(myList,position)
myList[position]=ITEM
print("The list after inserting",ITEM,"is")
print(myList)