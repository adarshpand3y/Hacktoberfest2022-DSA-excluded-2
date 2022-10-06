def linearsearch(nums, N, target):
    for i in range(N):
        if (nums[i] == target):
            return i
    return -1
 
 
# Driver Code

nums = list(map(int,input().split()))
target = int(input())
N = len(nums)
 
# Function call
ans = linearsearch(nums, N, target)
if(ans == -1):
    print("Element Is Not Present In Array")
else:
    print("Element Is Present at Index", ans)
