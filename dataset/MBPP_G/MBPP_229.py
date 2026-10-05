def re_arrange_array(arr, n):
    i = 0
    for j in range(n):
        if arr[j] < 0:
            arr[i], arr[j] = (arr[j], arr[i])
            i += 1
    return arr