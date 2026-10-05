def multiply_num(numbers):
    product = 1
    for number in numbers:
        product *= number
    return product / len(numbers)