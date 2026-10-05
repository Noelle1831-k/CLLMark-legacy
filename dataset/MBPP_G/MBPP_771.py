def check_expression(exp):
    stack = []
    matching_brackets = {')': '(', '}': '{', ']': '['}
    for char in exp:
        if char in matching_brackets.values():
            stack.append(char)
        elif char in matching_brackets.keys():
            if stack == [] or stack.pop() != matching_brackets[char]:
                return False
    return stack == []