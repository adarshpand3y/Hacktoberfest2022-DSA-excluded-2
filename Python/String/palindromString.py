# function which return reverse of a string
def isPalindrome(s):
    return s == s[::-1]

# Driver code
s = input("Enter a string: ")
ans = isPalindrome(s)

#checking condition
if ans:
    print("Palindrome")
else:
    print("Not palindrome")
