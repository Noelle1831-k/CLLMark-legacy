def get_pairs_count(arr, n, sum):
    count = 0
    freq = {}
    for num in arr:
        complement = sum - num
        if complement in freq:
            count += freq[complement]
        if num in freq:
            freq[num] += 1
        else:
            freq[num] = 1
    return count