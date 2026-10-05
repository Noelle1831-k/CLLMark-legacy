def check(arr, n):
    left, right = (0, n - 1)
    prev = float('-inf')
    while left <= right:
        if arr[left] <= arr[right]:
            if arr[left] >= prev:
                prev = arr[left]
                left += 1
            else:
                return False
        elif arr[right] >= prev:
            prev = arr[right]
            right -= 1
        else:
            return False
    return True