def get_Pairs_Count(arr, n, sum):
    count = 0
    freq = {}
    for num in arr:
        if sum - num in freq:
            count += freq[sum - num]
        if num in freq:
            freq[num] += 1
        else:
            freq[num] = 1
    return count