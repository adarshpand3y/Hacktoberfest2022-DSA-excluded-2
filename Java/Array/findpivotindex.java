class Solution {
    public int pivotIndex(int[] nums) {
        for(int i = 0; i < nums.length; i++){
        int left = 0;
        int right = 0;
       
        int pivot = i;
        for(int j = 0; j < i; j++){
            left = left + nums[j];
        }
        for(int k = i+1; k < nums.length; k++){
            right = right + nums[k];
        }
        if(left == right){
            return pivot;
        }
    }
        return -1;
    }
}
