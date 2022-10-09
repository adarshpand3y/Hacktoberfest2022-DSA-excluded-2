def kthSmallest(arr,n,k):
    arr.sort()
    return arr[k-1]

def kthLargest(arr,n,k):
    arr.sort()
    return arr[n-k]

if __name__=='__main__':
    arr=list(map(int,input().split()))
    n=len(arr)
    k=int(input("Kth largest and smallest in array: "))

    print("K'th smallest element is: ",kthSmallest(arr,n,k))
    print("K'th largest element is: ",kthLargest(arr,n,k))

