def max_sum_pair_diff_lessthan_K(arr, N, K):
    arr.sort(reverse=True)
    result = 0
    used = [False] * N
    for i in range(N):
        if used[i]:
            continue
        for j in range(i + 1, N):
            if not used[j] and abs(arr[i] - arr[j]) < K:
                result += arr[i] + arr[j]
                used[i] = used[j] = True
                break
    return result