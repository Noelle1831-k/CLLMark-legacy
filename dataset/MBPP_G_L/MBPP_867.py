def min_Num(arr, n):
    total_sum = sum(arr)
    if total_sum % 2 == 0:
        return 0
    else:
        return 1 if any((num % 2 != 0 for num in arr)) else 2