#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int n)
{
	int sum = 0; 

	for (int i = 0; i < n; i++){
        sum = sum + arr[i];
	}
	
	return sum;
}

// Driver code
int main()
{
	cout<<"Enter the number of elments of the array(1 to 100)"<<endl;
    int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	cout << "Sum of given array is " << sum(arr, n);
	return 0;
}

