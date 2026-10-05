def max_Abs_Diff(arr, n):
    max_element = arr[0]
    min_element = arr[0]
    for i in range(1, n):
        if arr[i] > max_element:
            max_element = arr[i]
        if arr[i] < min_element:
            min_element = arr[i]
    return max_element - min_element
print(max_Abs_Diff((2, 1, 5, 3), 4))
print(max_Abs_Diff((9, 3, 2, 5, 1), 5))
print(max_Abs_Diff((3, 2, 1), 3))