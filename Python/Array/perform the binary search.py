# (d) write a python program to perform the binary search

def binary_search(array, item):
    low = 0
    high = len(array) - 1

    while low <= high:
        mid = (low + high) // 2
        guess = array[mid]
        if guess == item:
            return mid
        if guess > item:
            high = mid - 1
        else:
            low = mid + 1
    return None


array = [100, 260, 300, 458, 590, 684, 750, 834, 990, 107]
item = int(input("Enter the item to be searched: "))
index = binary_search(array, item)
if index == -1:
    print("The item is not found")
else:
    print("Item is found at index: ", index)

print(array)