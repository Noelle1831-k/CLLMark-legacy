from collections import Counter

def n_common_words(text, n):
    words = text.split()
    word_counts = Counter(words)
    return word_counts.most_common(n)