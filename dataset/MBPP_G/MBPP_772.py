def remove_length(test_str, K):
    words = test_str.split()
    result = [word for word in words if len(word) != K]
    return ' '.join(result)