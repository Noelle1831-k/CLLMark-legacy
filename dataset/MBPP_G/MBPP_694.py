def extract_unique(test_dict):
    return sorted(set((val for values in test_dict.values() for val in values)))