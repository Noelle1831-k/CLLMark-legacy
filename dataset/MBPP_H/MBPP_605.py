def prime_num(num):
    if num >= 2:
        for i in range(2, num // 2 + 1):
            if (num % i) == 0:
                return False
        return True
    else:
        return False