def sort012(a,n):
    lo=0
    mi=0
    hi=n-1

    while mi<=hi:
        if a[mi]==0:
            a[lo],a[mi]=a[mi],a[lo]
            lo=lo+1
            mi=mi+1
        
        elif a[mi]==1:
            mi=mi+1

        else:
            a[mi],a[hi]=a[hi],a[mi]
            hi=hi-1
    return a

def printArray(a):
    for k in a:
        print(k,end=" ")

if __name__=='__main__':
    arr=list(map(int,input().split()))
    n=len(arr)
    arr=sort012(arr,n)
    printArray(arr)
