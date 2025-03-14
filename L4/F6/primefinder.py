def isPrime(n):
    if n <= 1:
        return False
    elif n <= 3:
        return True
    elif n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    squareroot = int(n**0.5)
    while i <= squareroot:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True


def firstPrimeSmallerThan(n):
    if n <= 1:
        return None
    elif n <= 3:
        return n
    elif n % 2 == 0:
        n -= 1
    else:
        n -= 2
    while n > 0:
        if isPrime(n):
            return n
        n -= 2
    return None


ulongmax = 4294967295
print("The largest prime number smaller than 4294967295 is: " + str(firstPrimeSmallerThan(ulongmax)))
