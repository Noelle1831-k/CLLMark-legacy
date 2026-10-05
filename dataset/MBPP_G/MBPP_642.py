def remove_similar_row(test_list):
    return set((tuple(sorted(row)) for row in test_list))