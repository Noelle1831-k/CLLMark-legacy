def is_valid_parenthese(str1):
    stack = []
    mapping = {')': '(', '}': '{', ']': '['}
    for char in str1:
        if char in mapping:
            top_element = stack.pop() if stack else '#'
            if mapping[char] != top_element:
                return False
        else:
            stack.append(char)
    return not stack