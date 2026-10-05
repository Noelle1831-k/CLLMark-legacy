def validate(n):
    for i in range(10):
        temp = n;
        count = 0;
        while (temp):
            if (temp % 10 == i):
                count += 1;
            if (count > i):
                return False
            temp //= 10;
        if (count != i):
            return False
    return True