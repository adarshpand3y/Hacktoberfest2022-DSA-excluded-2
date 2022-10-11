'''
File created by @shubharthaksangharsha
Task: Updated Linear Search in more Pythonic Way 
'''
from typing import List

def linear_search(arr: List[int], element: int) -> int:
    '''
    Returns the index of `element` from arr of list if found else return -1

    Params:
        arr(List): list of int elements
        element(int): element to be searched

    Returns:
        int: index of element if found else return -1 
    '''
    for i, v in enumerate(arr):
        if v == element:
            return i
    return -1

def check_result(ans: int, element: int) -> None:
    '''
    Print the answer of linear_search

    Params:
        ans(int): answer of linear_search funct
        element(int): element to be searched

    Returns:
       Returns None 
    '''
    if ans != -1:
        print(f"Element {element} found at index {ans}")
    else:
        print(f"Element {element} not found at any index")
    

if __name__ == "__main__":
    arr = list(map(int, input("Please Enter the List of elements sepereated by space: ").split()))
    element = int(input("Please Enter the element to be searched: "))
    check_result(linear_search(arr, element), element)
