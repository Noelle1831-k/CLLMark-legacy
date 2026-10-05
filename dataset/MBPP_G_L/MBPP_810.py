def count_variable(a, b, c, d):
    result = []
    letters = ['p', 'q', 'r', 's']
    counts = [a, b, c, d]
    for i in range(4):
        result.extend([letters[i]] * counts[i])
    return result