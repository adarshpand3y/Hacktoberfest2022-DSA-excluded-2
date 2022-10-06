def binary_search(lo,hi,condition):
    '''This is generic binary search method
    which take initial value as lo, hi value 
    as hi and also take your condition '''
    while hi>=lo:
        mid=(hi+lo)//2
        result=condition(mid)
        if result=='found':
            return mid
        elif result=='left':
            hi=mid-1
        elif result=='right':
            lo=mid+1
    return -1

'''Now I am going to solve a question using binary_search method
for your better understanding.
Question 2 : Given an array of integers nums sorted in ascending order, 
find the starting and ending position of a given number.'''

def first_position(nums,target):
    '''this method find first position of number'''
    def condition(mid):
        if nums[mid]==target:
            if mid >0 and nums[mid-1]==target:
                return 'left'
            return 'found'
        elif nums[mid]<target:
            return 'right'
        return 'left'
    return binary_search(0,len(nums)-1, condition)
    
def last_position(nums,target):
    '''this method find last position of number'''
    def condition(mid):
        if nums[mid]==target:
            if mid <len(nums)-1 and nums[mid+1]==target:
                return 'right'
            return 'found'
        elif nums[mid]<target:
            return 'right'
        return 'left'
    return binary_search(0,len(nums)-1, condition)
            
def first_last_position(nums, target):
    return first_position(nums, target), last_position(nums, target)

print(first_last_position([1,2,3,4,4,4],4))