def find_triplet_array(A, arr_size, sum):
    A.sort()
    for i in range(arr_size - 2):
        left = i + 1
        right = arr_size - 1
        while left < right:
            current_sum = A[i] + A[left] + A[right]
            if current_sum == sum:
                return (A[i], A[left], A[right])
            elif current_sum < sum:
                left += 1
            else:
                right -= 1
    return None