def modular_inverse(arr, N, P):
    count = 0
    for num in arr:
        if pow(num, P - 2, P) == num % P:
            count += 1
    return count