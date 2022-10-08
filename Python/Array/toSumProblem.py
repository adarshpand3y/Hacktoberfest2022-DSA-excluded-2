
# One of the very popular QUESTION


def twoSum(n, nums, target):
    # Time Complexity = O(n**2) 
    # Time Limit will exceed with certain cases
    for i in range(len(nums)): #for the rows
        for j in range(len(nums)): #respective columns
            if nums[i]+nums[j] == target and i!=j:
                    return [min(i,j),max(i,j)]



# Function call is done here 
print(twoSum(6,[1,2,3,4,5,6,23],9))
#try e