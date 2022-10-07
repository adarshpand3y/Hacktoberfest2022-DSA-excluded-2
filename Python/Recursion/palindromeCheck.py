#Check whether a string is palindrome or not using recursion

def palindrome(s):
    if len(s) < 1:
        return True
    else:
        if s[0] == s[-1]:
            return palindrome(s[1:-1])
        else:
            return False
#input 
NewStr=input("Enter A String : ")

if palindrome(NewStr) == True:
    print("Its Palindrome")
else:
    print("Not Palindrome")
    
