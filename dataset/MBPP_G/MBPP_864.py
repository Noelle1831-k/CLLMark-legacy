def palindrome_lambda(texts):
    return list(filter(lambda text: text == text[::-1], texts))