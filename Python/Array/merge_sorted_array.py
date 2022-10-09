'''
Problem - 
    Given two sorted arrays arr1[] of size N and arr2[] of size M. 
    Each array is sorted in non-decreasing order. 
    Merge the two arrays into one sorted array in non-decreasing order 
    without using any extra space.

    Expected Time Complexity: O((n+m)*log(n+m))
    Expected Auxiliary Space: O(1)

Example -
    Input:
        N = 4, M = 5
        arr1 = {1, 3, 5, 7}
        arr2 = {0, 2, 6, 8, 9}
    Output:
        0 1 2 3 5 6 7 8 9
'''


# Function to merge two arrays

def merge_array(arr1, n, arr2, m):
    i,j = n-1,0
    while i>=0 and j<m:
        if arr1[i] > arr2[j]:
            arr1[i],arr2[j] = arr2[j],arr1[i]
        i -= 1
        j += 1
    arr1.sort()
    arr2.sort()


# Main Code
n = int(input("Enter Size of First Array : "))
arr1 = list(map(int, input("Enter Array of first Elements : ").split()))
m = int(input("Enter Size of Second Array : "))
arr2 = list(map(int, input("Enter Array of second Elements : ").split()))

merge_array(arr1,n,arr2,m)

print("Merged Array is : ")
for i in arr1:
    print(i, end = " ")
for i in arr2:
    print(i, end = " ")
