def char_frequency(str1):
    return {char: str1.count(char) for char in set(str1)}