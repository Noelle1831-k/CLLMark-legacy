def find_literals(text, pattern):
    pattern = 'fox'
    text = 'The quick brown fox jumps over the lazy dog.'
    match = re.search(pattern, text)
    s = match.start()
    e = match.end()
    return (match.re.pattern, s, e)