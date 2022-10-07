
// Pseudocode:-----------

// Initialize:-----------
//     max_so_far = INT_MIN
//     max_ending_here = 0

// Loop for each element of the array

//   (a) max_ending_here = max_ending_here + a[i]
//   (b) if(max_so_far < max_ending_here)
//             max_so_far = max_ending_here
//   (c) if(max_ending_here < 0)
//             max_ending_here = 0
// return max_so_far


// C++ program to print largest contiguous array sum

#include <bits/stdc++.h> // this library/header file included all basic library which is use commonly
using namespace std;

int maxSubArraySum(int a[], int size)
{
	int max_so_far = INT_MIN, max_ending_here = 0;

	for (int i = 0; i < size; i++) {
		max_ending_here = max_ending_here + a[i];
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if (max_ending_here < a[i]) //if max_ending_here is less than a[i] means it will also work for negative numbers
			max_ending_here = a[i];
	}
	return max_so_far;
}


int main()
{
	int arr[] = { -2,1,-3,4,-1,2,1,-5,4 };

    // if you wish user input to this arry to use for loop ans take input
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function Call
	int max_sum = maxSubArraySum(arr, n);
	cout << "Maximum contiguous sum is " << max_sum<<endl;
	return 0;
}
