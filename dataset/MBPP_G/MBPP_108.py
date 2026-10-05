def merge_sorted_list(num1, num2, num3):
    import heapq
    merged_list = heapq.merge(sorted(num1), sorted(num2), sorted(num3))
    return list(merged_list)