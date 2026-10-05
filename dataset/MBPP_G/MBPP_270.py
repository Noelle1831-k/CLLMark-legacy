def sum_even_and_even_index(arr, n):
    return sum((arr[i] for i in range(0, n, 2) if arr[i] % 2 == 0))