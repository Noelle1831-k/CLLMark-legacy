def find_literals(text, pattern):
    match = re.search(re.escape(pattern), text)
    if match:
        start = match.start()
        end = match.end()
        return (pattern, start, end)
    return None