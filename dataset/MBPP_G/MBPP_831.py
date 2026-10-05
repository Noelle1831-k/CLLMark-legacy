def count_Pairs(arr, n):
    count = 0
    freq = {}
    for num in arr:
        if num in freq:
            count += freq[num]
            freq[num] += 1
        else:
            freq[num] = 1
    return count