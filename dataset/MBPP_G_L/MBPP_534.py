def search_literal(pattern, text):
    start = text.find(pattern)
    if start == -1:
        return None
    end = start + len(pattern)
    return (start, end)