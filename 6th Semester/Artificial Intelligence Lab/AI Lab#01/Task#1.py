def fib(a, b, n):
    if(n == 10):
        return
    print(n+1, ": ", a)
    fib(b, a+b, n+1)
fib(0,1,0)