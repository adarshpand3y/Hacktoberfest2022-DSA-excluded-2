//sorted and rotated array
#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target)
{
  int s=0,e=nums.size()-1;
  while (s<=e)
  {
    int mid=s+(e-s)/2;
    if (target==nums[mid])
      return mid;
    if(nums[s]>nums[mid]){
      if(nums[mid]<target && target<nums[e])
        s-mid+1;
      else
        e=mid-1;
    }
    else if (nums[e]<nums[mid]){
      if (nums[s]<target && target<nums[mid])
        e=mid-1;
      else
        s=mid+1;     
    }
    else{
      if(target<nums[mid])
        e=mid-1;
      else
        s=mid+1;
    }
  }
  return -1;
}