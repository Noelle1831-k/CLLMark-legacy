def count_vowels(test_str):
    vowels = 'aeiouAEIOU'
    count = 0
    for i in range(1, len(test_str) - 1):
        if test_str[i] not in vowels and (test_str[i - 1] in vowels or test_str[i + 1] in vowels):
            count += 1
    return count