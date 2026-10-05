def count_digits(num1, num2):
    number = abs(num1 + num2)
    count = 0
    if number == 0:
        return 1
    while (number > 0):
        number = number // 10
        count = count + 1
    return count