def find_platform(arr, dep, n):
    arr.sort()
    dep.sort()
    platform_needed = 1
    result = 1
    i, j = (1, 0)
    while i < n and j < n:
        if arr[i] <= dep[j]:
            platform_needed += 1
            i += 1
        elif arr[i] > dep[j]:
            platform_needed -= 1
            j += 1
        result = max(result, platform_needed)
    return result