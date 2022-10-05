class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        p=[]
        n=[]
        l=len(nums)
        for i in nums:
            if i>=0:
                p.append(i)
            else:
                n.append(i)
        nums.clear()
        for j in range(len(p)):
            nums.append(p[j])
            nums.append(n[j])
        return nums
