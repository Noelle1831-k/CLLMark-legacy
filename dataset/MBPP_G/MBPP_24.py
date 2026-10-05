def binary_to_decimal(binary):
    binary_str = str(binary)
    decimal = 0
    for i, digit in enumerate(reversed(binary_str)):
        decimal += int(digit) * 2 ** i
    return decimal