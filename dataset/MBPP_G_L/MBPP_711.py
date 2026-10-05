def product_Equal(n):
    even_product = 1
    odd_product = 1
    digits = str(n)
    for i in range(len(digits)):
        if (i + 1) % 2 == 0:
            even_product *= int(digits[i])
        else:
            odd_product *= int(digits[i])
    return even_product == odd_product