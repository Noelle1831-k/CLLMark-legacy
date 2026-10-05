def max_sum_increasing_subseq(a, n, index, k):
    if k <= index or index < 0 or k >= n:
        return 0
    max_sum = 0
    for i in range(index + 1):
        if a[i] < a[k]:
            curr_sum = a[i]
            for j in range(i):
                if a[j] < a[i]:
                    curr_sum = max(curr_sum, a[j] + a[i])
            max_sum = max(max_sum, curr_sum)
    return max_sum + a[k]