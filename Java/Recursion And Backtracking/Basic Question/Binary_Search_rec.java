
/*


Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
*/

class Solution {
    public int search(int[] nums, int target) {
        
   return recSearch(nums,target,0,nums.length-1);
    }
    
    public static int recSearch(int[] arr, int target, int s, int e){
        if(s<=e){
            int mid = s+(e-s)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]<target){
            return recSearch(arr, target, mid+1, e);
        }
     
            return recSearch(arr, target, s, mid-1);
  
        }
        
        return -1;
    }
}
