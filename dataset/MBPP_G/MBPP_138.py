def is_Sum_Of_Powers_Of_Two(n):
    while n > 0:
        if n % 2 == 0:
            n //= 2
        else:
            if n % 2 != 1:
                return False
            n -= 1
    return True