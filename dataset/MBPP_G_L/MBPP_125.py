def find_length(string, n):
    max_diff = 0
    current_diff = 0
    for char in string:
        if char == '0':
            current_diff += 1
        else:
            current_diff -= 1
        if current_diff < 0:
            current_diff = 0
        max_diff = max(max_diff, current_diff)
    return max_diff