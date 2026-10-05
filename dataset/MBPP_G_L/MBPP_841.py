def get_inv_count(arr, n):
    inv_count = 0
    for i in range(n):
        for j in range(i + 1, n):
            if arr[i] > arr[j]:
                inv_count += 1
    return inv_count
print(get_inv_count([1, 20, 6, 4, 5], 5))
print(get_inv_count([8, 4, 2, 1], 4))
print(get_inv_count([3, 1, 2], 3))