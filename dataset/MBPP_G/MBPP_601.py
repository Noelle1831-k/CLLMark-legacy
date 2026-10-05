def max_chain_length(arr, n):
    arr.sort(key=lambda x: x[1])
    max_length = 1
    last_selected_pair = arr[0]
    for i in range(1, n):
        if arr[i][0] > last_selected_pair[1]:
            max_length += 1
            last_selected_pair = arr[i]
    return max_length
print(max_chain_length([(5, 24), (15, 25), (27, 40), (50, 60)], 4))
print(max_chain_length([(1, 2), (3, 4), (5, 6), (7, 8)], 4))
print(max_chain_length([(19, 10), (11, 12), (13, 14), (15, 16), (31, 54)], 5))