def parse_code_structure(tokens):
    structure = []
    indent_level = 0
    for token in tokens:
        if token in ['if', 'for', 'while']:
            structure.append('start')
            indent_level += 1
        elif token == ':':
            # Assuming ':' indicates the start of a block
            structure.append('start')
        elif token == 'dedent':
            # Assuming 'dedent' indicates the end of a block
            structure.append('end')
            indent_level -= 1
    return structure