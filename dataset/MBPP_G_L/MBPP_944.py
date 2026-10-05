def num_position(text):
    match = re.search('\\d+', text)
    if match:
        print(match.start())
    else:
        print(-1)