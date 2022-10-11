'''
Left Rotation of Array

In this program, we need to rotate the array towards the left by the specified number of elements.
'''

# function to left rotate an array
def rotateArray(arr, n, d):   # d denotes the no. of elements by which the array is rotated to the left
    temp = []
    i = 0
    while (i < d):
        temp.append(arr[i])
        i = i + 1
    i = 0
    while (d < n):
        arr[i] = arr[d]
        i = i + 1
        d = d + 1
    arr[:] = arr[: i] + temp
    return arr
 
 
# test array
arr = [1, 2, 3, 4, 5, 6, 7]

print("Array after left rotation: ", end=' ')
# function call
print(rotateArray(arr, len(arr), 3))