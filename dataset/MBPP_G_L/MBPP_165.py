def count_char_position(str1):
    count = 0
    for index, char in enumerate(str1):
        position = ord(char.lower()) - ord('a') + 1
        if position == index + 1:
            count += 1
    return count