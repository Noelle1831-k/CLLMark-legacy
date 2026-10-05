def num_position(text):
    import re
    match = re.search('\\d+', text)
    if match:
        print(match.start())
    else:
        print(-1)