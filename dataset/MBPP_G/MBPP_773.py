def occurance_substring(text, pattern):
    start = text.find(pattern)
    if start == -1:
        return None
    end = start + len(pattern)
    return (pattern, start, end)