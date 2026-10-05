def find_Product(arr, n):
    arr.sort()
    prod = 1
    for i in range(n):
        if i == 0 or (arr[i - 1] != arr[i]):
            prod = prod * arr[i]
    return prod;