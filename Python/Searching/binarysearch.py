"Binary Search Implementation"



def BinarySearchIterative(array: list, searchForValue)->int:
    low = 0
    high = len(array) - 1

    while low <= high:
        mid = (low + high) // 2
        
        if array[mid] > searchForValue:
            high = mid - 1
        elif array[mid] < searchForValue:
            low = mid + 1
        else:
            # array[mid] == searchForValue
            return mid
    
    return -1


def BinarySearchRecurssive(array:list, searchForValue:int, low:int, high:int)->int:
    if low <= high:

        mid = (low + high) // 2

        if array[mid] > searchForValue:
            return BinarySearchRecurssive(array, searchForValue, low, mid - 1)
        elif array[mid] < searchForValue:
            return BinarySearchRecurssive(array, searchForValue, mid + 1, high)
        else:
            # array[mid] == searchForValue
            return mid
    return - 1