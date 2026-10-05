def diff_even_odd(list1):
    for num in list1:
        if num % 2 == 0:
            first_even = num
            break
    for num in list1:
        if num % 2 != 0:
            first_odd = num
            break
    return abs(first_even - first_odd)