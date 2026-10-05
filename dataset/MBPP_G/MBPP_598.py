def armstrong_number(number):
    digits = str(number)
    num_digits = len(digits)
    total = sum((int(digit) ** num_digits for digit in digits))
    return total == number