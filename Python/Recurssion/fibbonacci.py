n = int(input())
ans = ''

def fibo(n):
    if n <= 1:
        return n
    else:
        return(fibo(n-1) + fibo(n-2))

if n <= 0:
    print("Please Enter Positive Integer")
else:
    print("Fibonacci Series :")
    for i in range(n):
       ans += str(fibo(i))
       ans+=' '
    print(ans)
