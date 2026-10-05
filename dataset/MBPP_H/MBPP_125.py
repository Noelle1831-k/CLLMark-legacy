def find_length(string, n):
    current_sum = 0
    max_sum = float('-inf')
    for i in range(n):
        current_sum += (1 if string[i] == '0' else -1)
        if current_sum < 0:
            current_sum = 0
        max_sum = max(current_sum, max_sum)
    return max_sum if max_sum != float('-inf') else 0