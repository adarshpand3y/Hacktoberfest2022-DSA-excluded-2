#PASCAL'S TRIANGLE USING RECURSION
#for Pascal's Triangle every element is calculated by the formula nCr combination formula
#nCr combination formula=Factorial of n/(factorial of r)*(factorial of n-r)
def Factorial(a):#factorial calculation
    f = 1
    if a == 0:
        return f
    else:
        for i in range(1, a+1):
            f = f*i
        return f

#input
Rows = int(input("Enter the number of rows ="))
for i in range(0, Rows):
    for k in range(Rows-i+1):
        print(end=" ")#for the spacing
    for j in range(i+1):
        Combination = Factorial(i)/(Factorial(j)*Factorial(i-j))#combination calculation
        print("%d" % Combination, end=" ")
    print("\n")
