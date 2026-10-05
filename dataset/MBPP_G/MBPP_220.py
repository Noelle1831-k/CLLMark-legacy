def replace_max_specialchar(text, n):
    special_chars = ' ,.'
    count = 0
    result = []
    for char in text:
        if char in special_chars and count < n:
            result.append(':')
            count += 1
        else:
            result.append(char)
    return ''.join(result)