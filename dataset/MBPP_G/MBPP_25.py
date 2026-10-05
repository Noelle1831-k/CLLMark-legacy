def find_Product(arr, n):
    unique_elements = set(arr)
    product = 1
    for elem in unique_elements:
        if arr.count(elem) == 1:
            product *= elem
    return product if product != 1 else 0