def min_jumps(arr, n):
    if n <= 1:
        return 0
    if arr[0] == 0:
        return float('inf')
    max_reach = arr[0]
    step = arr[0]
    jump = 1
    for i in range(1, n):
        if i == n - 1:
            return jump
        max_reach = max(max_reach, i + arr[i])
        step -= 1
        if step == 0:
            jump += 1
            if i >= max_reach:
                return float('inf')
            step = max_reach - i
    return float('inf')
print(min_jumps([1, 3, 6, 1, 0, 9], 6))
print(min_jumps([1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9], 11))
print(min_jumps([1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], 11))