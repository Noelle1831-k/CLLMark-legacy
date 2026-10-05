def extract_elements(numbers, n):
    result = []
    for i in range(len(numbers) - n + 1):
        if len(set(numbers[i:i + n])) == 1:
            result.append(numbers[i])
    return result