def exchange_elements(lst):
    return [lst[i + 1] if i % 2 == 0 else lst[i - 1] for i in range(len(lst))]