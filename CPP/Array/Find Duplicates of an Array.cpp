
// Cpp program to find all duplicates in the given array
#include <bits/stdc++.h>
using namespace std;
 
// function to find and print duplicates
void findDuplicates(int array[], int n)
{
    // unordered_map to store frequencies
    unordered_map<int, int> frequency;
    for (int i=0; i<n; i++)
        frequency[array[i]]++;
 
    bool dup = false;
    unordered_map<int, int> :: iterator i;
    
    for (i=frequency.begin(); i!=frequency.end(); i++)
    {
        // if frequency is more than or equal to 2 print the element
        if (i->second >= 2)
        {
            cout << i->first << " ";
            dup = true;
        }
    }
 
    // no duplicates present
    if (dup == false)
        cout << "their is no duplicate elements in the array"<<endl;
}
 
//main function
int main()
{
	int n; //size of array
	cin>>n;
    int array[n] ;
    for (int i=0; i<n; i++){
    	cin>>array[i];
	}
    findDuplicates(array, n);
    return 0;
}