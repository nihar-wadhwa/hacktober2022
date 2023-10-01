if n == 0:
            return 0
        if n == 1:
            return 1
        fibo = printFibb(n-1) + printFibb(n-2)
        return fibo
