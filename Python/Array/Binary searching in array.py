def Bsearch(AR,ITEM):
    beg= 0
    last =len(AR) -1
    while (beg<=last):
        mid =(beg+last)/2
        if(ITEM==AR[mid]):
            return mid
        elif (ITEM> AR[mid]):
            beg=mid +1
        else:
            last =mid-1
    else:
        return False
# __main__
N=int(input("Enter Desired linear -list size(max.50)...."))
print("\nEnter elements for Linear list In Ascending Order\n")
AR=[0]*N
for i in range(N):
    AR[i]=int(input("\nEnter Element to be searched for...."))
    index =Bsearch(AR,ITEM)

    if index:
        print("\nElemnt found at index: ",index,",Position:",(index+1))
    else:
        print("\nSoryy!! ZGiven element could not be found.\n")