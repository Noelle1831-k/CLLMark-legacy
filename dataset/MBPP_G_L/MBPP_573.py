def unique_product(list_data):
    unique_numbers = set(list_data)
    product = 1
    for num in unique_numbers:
        product *= num
    return product