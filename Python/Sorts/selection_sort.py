from typing import List
def minFunc(arr:List[int], start:int, stop:int)->tuple:
    '''
    input : takes a integer list and any integer starting, stopping index  from the list
    output: return min_element and min_index as tuple
    '''
    min_element = arr[start]
    min_index = start
    while start != stop:
        if arr[start] <= min_element:
            min_element = arr[start]
            min_index = start
        start += 1
    return min_element,min_index

def selectionSort(arr:List[int])->None:
    '''
    Sort the given input list in-place.
    input: List[int] 
    output: None
    '''
    for i in range(len(arr)):
        _, min_index = minFunc(arr,i,len(arr))
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return None

if __name__ == "__main__":  
    arr = list(map(int, input("Please enter array's elements seperated by space: ").split()))
    print("Array Before:", arr)
    selectionSort(arr)
    print("Array After:", arr)
