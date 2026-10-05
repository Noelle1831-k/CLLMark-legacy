def increment_numerics(test_list, K):
    return [str(int(item) + K) if item.isdigit() else item for item in test_list]