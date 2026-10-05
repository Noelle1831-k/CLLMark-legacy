def sum_of_digits(nums):
    total = 0
    for item in nums:
        if isinstance(item, int):
            total += sum((int(digit) for digit in str(abs(item))))
    return total