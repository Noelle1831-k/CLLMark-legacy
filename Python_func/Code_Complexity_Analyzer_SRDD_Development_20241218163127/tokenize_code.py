def tokenize_code(code):
    tokens = []
    current_token = ''
    for char in code:
        if char.isalnum() or char == '_':
            current_token += char
        else:
            if current_token:
                tokens.append(current_token)
                current_token = ''
            if char in [' ', '\n', '\t']:
                continue
            tokens.append(char)
    if current_token:
        tokens.append(current_token)
    return tokens