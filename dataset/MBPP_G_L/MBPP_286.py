def max_sub_array_sum_repeated(a, n, k):
    def kadane(arr):
        max_sum = current_sum = arr[0]
        for num in arr[1:]:
            current_sum = max(num, current_sum + num)
            max_sum = max(max_sum, current_sum)
        return max_sum
    total_sum = sum(a)
    max_kadane = kadane(a)
    if k == 1:
        return max_kadane
    prefix_sum = suffix_sum = 0
    max_prefix_sum = max_suffix_sum = float('-inf')
    for i in range(n):
        prefix_sum += a[i]
        max_prefix_sum = max(max_prefix_sum, prefix_sum)
    for i in range(n - 1, -1, -1):
        suffix_sum += a[i]
        max_suffix_sum = max(max_suffix_sum, suffix_sum)
    if total_sum > 0:
        return max(max_kadane, max_prefix_sum + max_suffix_sum + total_sum * (k - 2))
    else:
        return max(max_kadane, max_prefix_sum + max_suffix_sum)