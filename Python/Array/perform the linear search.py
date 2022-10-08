# (c) write a python program to perform the linear search


def linear_search(array, item):
    for i in range(len(array)):
        if array[i] == item:
            return i
    return -1


array = [15, 24, 36, 43, 55, 46, 74, 86, 39, 10]
item = int(input("Enter the item to be searched: "))
index = linear_search(array, item)
if index == -1:
    print("Item not found")
else:
    print("Item found at index: ", index)

print(array)