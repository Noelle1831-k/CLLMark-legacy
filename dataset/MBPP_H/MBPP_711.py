def product_Equal(n):
    if n < 10:
        return False
    prodOdd = 1
    prodEven = 1
    position = 1
    while n > 0:
        digit = n % 10
        if position % 2 == 1:
            prodOdd *= digit
        else:
            prodEven *= digit
        n = n // 10
        position += 1
    if prodOdd == prodEven:
        return True
    return False