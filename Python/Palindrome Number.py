#Name = Jogeswar Panigrahi
#Palindrome number
#Link=https://leetcode.com/problems/palindrome-number/


#code


class Solution:
    def isPalindrome(self, x: int) -> bool:
        # Base condition
        if x < 0:
            return False
        temp = x
        rev = 0
        while x > 0:
            dig = (x % 10)
            rev = (rev * 10) + dig
            x = x // 10
        if (temp == rev):
            return True
        else:
            return False