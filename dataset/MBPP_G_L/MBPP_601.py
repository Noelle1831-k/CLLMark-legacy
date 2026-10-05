def max_chain_length(arr, n):
    arr.sort(key=lambda x: x[1])
    max_length = 1
    last_selected_pair = arr[0]
    for i in range(1, n):
        if arr[i][0] > last_selected_pair[1]:
            max_length += 1
            last_selected_pair = arr[i]
    return max_length
