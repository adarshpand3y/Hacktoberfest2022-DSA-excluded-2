# Merge sort algorithm
# Created by santosh50

def merge_sort(arr: list) -> None:
    if len(arr) > 1:
        mid = len(arr)//2
        L = arr[:mid]
        R = arr[mid:]
        merge_sort(L)
        merge_sort(R)
        i = j = k = 0
        while(i < len(L) and j < len(R)):
            if(L[i] < R[j]):
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        while(i < len(L)):
            arr[k] = L[i]
            i += 1
            k += 1
        while(j < len(R)):
            arr[k] = R[j]
            j += 1
            k += 1

def main():
    arr = [38, 27, 43, 3, 9, 82, 10]
    merge_sort(arr)
    print(*arr)

if __name__ == '__main__':
    main()
