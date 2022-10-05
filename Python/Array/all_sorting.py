###########################################
#                                         #
#             Bubble sort                 #
#       - Time Complexity : O(n*n)        #
#                                         #
###########################################


def bubbleSort(arr):
    n = len(arr)
    swapped = False
    for i in range(n-1):
        for j in range(0, n-i-1):
            if arr[j] > arr[j + 1]:
                swapped = True
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
        if not swapped:
            return

###########################################
#                                         #
#          Selection sort                 #
#    - Time Complexity : O(n*n)           #
#                                         #
###########################################


def selectionSort(array, size):

    for ind in range(size):
        min_index = ind
        for j in range(ind + 1, size):
            if array[j] < array[min_index]:
                min_index = j
        (array[ind], array[min_index]) = (array[min_index], array[ind])


###########################################
#                                         #
#          Insertion sort                 #
#    - Time Complexity : O(n*n)           #
#                                         #
###########################################

def insertionSort(arr):

    for i in range(1, len(arr)):
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j]:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key


###########################################
#                                         #
#              merge sort                 #
#    - Time Complexity : O(n log(n))      #
#                                         #
###########################################


def merge(arr, l, m, r):
    n1 = m - l + 1
    n2 = r - m
    L = [0] * (n1)
    R = [0] * (n2)

    for i in range(0, n1):
        L[i] = arr[l + i]

    for j in range(0, n2):
        R[j] = arr[m + 1 + j]

    i = 0
    j = 0
    k = l

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1


def mergeSort(arr, l, r):
    if l < r:

        m = l+(r-l)//2
        mergeSort(arr, l, m)
        mergeSort(arr, m+1, r)
        merge(arr, l, m, r)

###########################################
#                                         #
#              Quick sort                 #
#    - Time Complexity : O(n*n)           #
#                                         #
###########################################


def partition(array, low, high):

    pivot = array[high]

    i = low - 1

    for j in range(low, high):
        if array[j] <= pivot:

            i = i + 1

            (array[i], array[j]) = (array[j], array[i])

    (array[i + 1], array[high]) = (array[high], array[i + 1])

    return i + 1


def quickSort(array, low, high):
    if low < high:

        pi = partition(array, low, high)

        quickSort(array, low, pi - 1)
        quickSort(array, pi + 1, high)


###########################################
#                                         #
#               Heap sort                 #
#    - Time Complexity : O(n*log(n))      #
#                                         #
###########################################



def heapify(arr, n, i):
	largest = i 
	l = 2 * i + 1
	r = 2 * i + 2 


	if l < n and arr[i] < arr[l]:
		largest = l



	if r < n and arr[largest] < arr[r]:
		largest = r



	if largest != i:
		(arr[i], arr[largest]) = (arr[largest], arr[i]) 
		heapify(arr, n, largest)

def heapSort(arr):
	n = len(arr)


	for i in range(n // 2 - 1, -1, -1):
		heapify(arr, n, i)


	for i in range(n - 1, 0, -1):
		(arr[i], arr[0]) = (arr[0], arr[i])
		heapify(arr, i, 0)




#---------Heap sort

arr = [12, 11, 13, 5, 6, 7, ]
heapSort(arr)
n = len(arr)
print('Sorted array is')
for i in range(n):
	print(arr[i])


# ----------- Quick Sort
data = [1, 7, 4, 1, 10, 9, -2]
print("Unsorted Array")
print(data)

size = len(data)

quickSort(data, 0, size - 1)

print('Sorted Array in Ascending Order:')
print(data)


# ---------Merge
arr = [12, 11, 13, 5, 6, 7]
n = len(arr)
print("Given array is")
for i in range(n):
    print("%d" % arr[i], end=" ")

mergeSort(arr, 0, n-1)
print("\n\nSorted array is")
for i in range(n):
    print("%d" % arr[i], end=" ")

# --------insertionSort
arr = [12, 11, 13, 5, 6]
insertionSort(arr)
lst = []
print("Sorted array is : ")
for i in range(len(arr)):
    lst.append(arr[i])
print(lst)

# -------selection
arr = [-2, 45, 0, 11, -9, 88, -97, -202, 747]
size = len(arr)
selectionSort(arr, size)
print('The array after sorting in Ascending Order by selection sort is:')
print(arr)

# ----------bubbleSort
arr = [64, 34, 25, 12, 22, 11, 90]

bubbleSort(arr)

print("Sorted array is:")
for i in range(len(arr)):
    print("% d" % arr[i], end=" ")
