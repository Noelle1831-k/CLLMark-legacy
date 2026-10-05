def find_First_Missing(array, start, end):
    if start > end:
        return end + 1
    if array[start] != start:
        return start
    mid = (start + end) // 2
    if array[mid] == mid:
        return find_First_Missing(array, mid + 1, end)
    else:
        return find_First_Missing(array, start, mid)