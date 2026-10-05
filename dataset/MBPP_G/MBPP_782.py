def Odd_Length_Sum(arr):
    total = 0
    n = len(arr)
    for i in range(n):
        total += arr[i] * ((i + 1) * (n - i) + 1) // 2
    return total