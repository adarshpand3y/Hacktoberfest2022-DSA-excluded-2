#include<bits/stdc++.h>
using namespace std;

int secondLargest(int arr[], int n) {
	    int i, first, second;
	    if (n < 2) {
	        return -1;
	    }
	    first = second = INT_MIN;
	    for (i = 0; i < n; i++) {
	        if (arr[i] > first) {
	            second = first;
	            first = arr[i];
	        }
	        else if (arr[i] > second && arr[i] != first) {
	            second = arr[i];
	        }
	    }
	    if (second == INT_MIN)
	        return -1;
	    else
	        return second;
	}
int main(){
    int n=6;
    int arr[n]={12, 35, 1, 10, 34, 1};
    cout<<secondLargest(arr, n);
    return 0;
}