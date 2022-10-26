def pivot(arr, start, end):
    pivot = arr[start]
    swap_index = start
    for i in range(start+1, end+1):
        if pivot > arr[i]:
            swap_index += 1
            arr[i], arr[swap_index] = arr[swap_index], arr[i]
    arr[start], arr[swap_index] = arr[swap_index], arr[start]
    return swap_index


# print(pivot([28, 41, 4, 11, 16, 1, 40, 14, 36, 37, 42, 18]))
# print(pivot([4, 8, 2, 1, 5, 7, 6, 3]))


def quick_sort(arr, left, right):
    if left < right:
        pivot_index = pivot(arr, left, right)
        quick_sort(arr, left, pivot_index-1)
        quick_sort(arr, pivot_index+1, right)
    return arr


print(quick_sort([4, 8, 2, 1, 5, 7, 6, 3], 0, 7))
print(quick_sort([28, 41, 4, 11, 16, 1, 40, 14, 36, 37, 42, 18], 0, 7))


# Time Complexity: O(nlogn) (For all Best and Average Case)  O(n*n) (Best case)
# ----------------------------------  Best and Average Case --------------------------------
# why logn because for dividing the array requires logn times into single element array
# if 32 element is present in arrray then 2^5 i.e 5 pases are required to divide it into single elements araays
# after decomposition we are doing array length (n) comparisions and then merging for sorting
# Hence Time Complexity: O (nlogn)
# ------------------------------------- Worst Case -----------------------------------------
# In worst case element is in sorted order hence by choosing first element as a pivot
# but since in sorted all the elements will be on right side hence divided into n decompositions
# and n comparisons in array hence O(n*n)

# Space Complexity: O(logn)
