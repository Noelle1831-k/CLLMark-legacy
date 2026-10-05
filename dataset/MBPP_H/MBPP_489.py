def frequency_Of_Largest(n, arr):
    mx = arr[0]
    freq = 1
    for i in range(1, n):
        if (arr[i] > mx):
            mx = arr[i]
            freq = 1
        elif (arr[i] == mx):
            freq += 1
    return freq