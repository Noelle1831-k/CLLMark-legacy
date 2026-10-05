def check_triplet(A, n, sum, count):
    A.sort()
    for i in range(n - 2):
        left = i + 1
        right = n - 1
        while left < right:
            if A[i] + A[left] + A[right] == sum:
                return True
            elif A[i] + A[left] + A[right] < sum:
                left += 1
            else:
                right -= 1
    return False