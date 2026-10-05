def anagram_lambda(texts, str):
    sorted_str = ''.join(sorted(str.replace(' ', '')))
    return list(filter(lambda x: ''.join(sorted(x.replace(' ', ''))) == sorted_str, texts))