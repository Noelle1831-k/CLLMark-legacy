def extract_symmetric(test_list):
    seen = set()
    symmetric_pairs = set()
    for a, b in test_list:
        if (b, a) in seen:
            symmetric_pairs.add((min(a, b), max(a, b)))
        seen.add((a, b))
    return symmetric_pairs