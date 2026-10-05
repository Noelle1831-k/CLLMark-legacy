def is_Two_Alter(s):
    if len(s) < 2:
        return False
    first_char, second_char = (s[0], s[1])
    if first_char == second_char:
        return False
    for i in range(len(s)):
        if i % 2 == 0 and s[i] != first_char:
            return False
        elif i % 2 == 1 and s[i] != second_char:
            return False
    return True