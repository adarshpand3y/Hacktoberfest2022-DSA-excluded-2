
# function which return reverse of a string
 def isPalindrome(s):
    return s == s[::-1]
 
 
# Driver code
s = "malayalam"
ans = isPalindrome(s)

#it will check condition and print yes or no
if ans:
    print("Yes")
else:
    print("No")
