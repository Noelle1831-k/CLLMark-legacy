def octal_To_Decimal(n):
    decimal_number = 0
    base = 1
    while n > 0:
        last_digit = n % 10
        n = n // 10
        decimal_number += last_digit * base
        base = base * 8
    return decimal_number