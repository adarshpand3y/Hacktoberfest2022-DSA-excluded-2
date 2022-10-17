#include <bits/stdc++.h>
using namespace std;
int maxsubarray(vector<int>& nums) 
{
    int maxsum=INT_MIN;
    int current=0;
    for(auto it:nums)
    {
        if(current<0) current=0;
        current += it;
        maxsum =  max(maxsum , current);
    }
    return maxsum;
}
int main(){
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<< maxsubarray(nums) <<endl;
return 0;
}