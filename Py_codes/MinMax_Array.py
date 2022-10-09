def getMinMax( arr, n):
    # If array has even number of elements then
    # initialize the first two elements as minimum
    # and maximum
    if(n % 2 == 0):
        mx = max(arr[0], arr[1])
        mn = min(arr[0], arr[1])
         
        # set the starting index for loop
        i = 2
         
    # If array has odd number of elements then
    # initialize the first element as minimum
    # and maximum
    else:
        mx = mn = arr[0]
         
        # set the starting index for loop
        i = 1
         
    # In the while loop, pick elements in pair and
    # compare the pair with max and min so far
    while(i < n - 1):
        if arr[i] < arr[i + 1]:
            mx = max(mx, arr[i + 1])
            mn = min(mn, arr[i])
        else:
            mx = max(mx, arr[i])
            mn = min(mn, arr[i + 1])
             
        # Increment the index by 2 as two
        # elements are processed in loop
        i += 2
     
    return (mn, mx)

def main():
    T=int(input())
    while(T>0):
        n=int(input())
        a=[int(x) for x in input().strip().split()]
        product=getMinMax(a,n)
        print(product[0],end=" ")
        print(product[1])
        T-=1

if __name__=="__main__":
    main()
