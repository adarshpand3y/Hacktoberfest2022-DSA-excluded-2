#include<stdio.h>

int binary_search(int nums[], int n, int target)
{
    int start = 0;
    int end = n - 1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(nums[mid] == target) // when the target element is presented in the array
            return mid;

        if(nums[mid] < target) // target element is greater than the current middle element
            start = mid + 1;
        else                  // target element is smaller than the current middle element
            end = mid - 1;
    }

    // target element is not presented in the array
    return -1;
}

int main()
{
    int nums[] = {1, 5, 10, 13, 15, 20, 25, 94};

    int n = sizeof(nums)/sizeof(nums[0]);

    int target = 94;

    int ans = binary_search(nums, n, target);

    if(ans != -1){
        printf("Index of the target value %d is %d.\n", target, ans);
    }
    else{
        printf("%d is not presented in the array.\n", target);
    }

    return 0;
}
