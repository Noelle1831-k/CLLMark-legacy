def merge_sort(x):
    if len(x) <= 1:
        return x
    mid = len(x) // 2
    left = merge_sort(x[0:mid])
    right = merge_sort(x[mid:])
    return merge(left, right)
def merge(left, right):
    sorted_list = []
    left_index, right_index = (0, 0)
    while left_index < len(left) and right_index < len(right):
        if left[left_index] < right[right_index]:
            sorted_list.append(left[left_index])
            left_index += 1
        else:
            sorted_list.append(right[right_index])
            right_index += 1
    sorted_list.extend(left[left_index:])
    sorted_list.extend(right[right_index:])
    return sorted_list