def check_last(arr, n, p):
    last_element = arr[-1]
    last_element += p * n
    if last_element % 2 == 0:
        return 'EVEN'
    else:
        return 'ODD'
result1 = check_last([5, 7, 10], 3, 1)
print(result1)
result2 = check_last([2, 3], 2, 3)
print(result2)
result3 = check_last([1, 2, 3], 3, 1)
print(result3)