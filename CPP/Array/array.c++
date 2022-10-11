//Find k’th largest element in an array
//Given an integer array, find k’th largest element in the array where k is a positive integer less than or equal to the length of array.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
// Function to find the k'th largest element in an array using min-heap
int findKthLargest(vector<int> const &ints, int k)
{
    // base case
    if (ints.size() < k) {
        exit(-1);
    }
 
    // create a min-heap using `std::priority_queue` and insert
    // the first `k` array elements into the heap
    // `std::greater` is used as the comparison function for min-heap
    priority_queue<int, vector<int>, greater<int>> pq(ints.begin(), ints.begin() + k);
 
    // do for remaining array elements
    for (int i = k; i < ints.size(); i++)
    {
        // if the current element is more than the root of the heap
        if (ints[i] > pq.top())
        {
            // replace root with the current element
            pq.pop();
            pq.push(ints[i]);
        }
    }
 
    // return the root of min-heap
    return pq.top();
}
 
int main()
{
    vector<int> ints = { 7, 4, 6, 3, 9, 1 };
    int k = 2;
 
    cout << "k'th largest array element is " << findKthLargest(ints, k);
 
    return 0;
}