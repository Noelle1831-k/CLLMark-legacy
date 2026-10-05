def extract_singly(test_list):
    from collections import Counter
    all_elements = [elem for sublist in test_list for elem in sublist]
    element_count = Counter(all_elements)
    return sorted([elem for elem, count in element_count.items() if count == 1])