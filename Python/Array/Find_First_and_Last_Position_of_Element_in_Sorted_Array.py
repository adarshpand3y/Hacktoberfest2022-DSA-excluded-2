class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if target not in nums:
            return [-1,-1]
        s=nums.index(target)
        p=nums.index(target)+nums.count(target)-1
        return [s,p]
