def replace_char(str1, ch, newch):
    return ''.join([newch if char == ch else char for char in str1])