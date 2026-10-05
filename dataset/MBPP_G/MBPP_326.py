def most_occurrences(test_list):
    from collections import Counter
    words = ' '.join(test_list).split()
    word_count = Counter(words)
    return word_count.most_common(1)[0][0]