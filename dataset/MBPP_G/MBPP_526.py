def capitalize_first_last_letters(str1):
    return ' '.join([word[0].upper() + word[1:len(word)-1] + word[-1].upper() if len(word) > 1 else word.upper() for word in str1.split()])