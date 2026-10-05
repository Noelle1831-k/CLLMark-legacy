def count_common(words):
    from collections import Counter
    count = Counter(words)
    most_common = count.most_common()
    max_count = most_common[0][1]
    result = [word for word in most_common if word[1] == max_count]
    result.extend((w for w in most_common if w[1] < max_count and w not in result))
    return result[0:5]