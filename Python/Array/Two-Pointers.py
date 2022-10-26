# Searching TargetSum for an element-pair using 2 pointer technique
# when we need to find the pair whose sum is euqal to target then the brute force technique takes O(N^2) whereas Two pointer techniques takes O(N) time complexity
# PS-Two pointer works on sorted array
def Twopointer(Arr,Target):
  left=0
  right=len(Arr)-1
  while(left<=right):
    temp=Arr[left] +Arr[right]
    if temp==Target:
      return [left,right]
    elif temp>Target:
      right-=1
    else:
      left+=1
  return [-1,-1]


#driver-code
Arr=list(map(int,input("Enter Array").split()))
Target=int(input("Enter TargetSum"))

#calling function
ans=Twopointer(Arr,Target)

if ans==[-1,-1]:
  print("Pair with Target sum does not exist")
else:
  print(f"The target pair index are {ans}")

