def replace(string, char):
    result = []
    prev_char = None
    for c in string:
        if c == char and prev_char == char:
            continue
        result.append(c)
        prev_char = c
    return ''.join(result)