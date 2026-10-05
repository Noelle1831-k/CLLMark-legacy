def divisible_by_digits(startnum, endnum):
    result = []
    for num in range(startnum, endnum + 1):
        digits = [int(d) for d in str(num) if d != '0']
        if all((num % d == 0 for d in digits)):
            result.append(num)
    return result