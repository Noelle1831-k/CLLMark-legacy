def find_minimum_range(lists):
    import heapq
    range_start, range_end = (float('-inf'), float('inf'))
    max_value = float('-inf')
    heap = []
    for i, group in enumerate(lists):
        element = group[0]
        heapq.heappush(heap, (element, i, 0))
        max_value = max(max_value, element)
    while heap:
        min_value, list_idx, element_idx = heapq.heappop(heap)
        if max_value - min_value < range_end - range_start:
            range_start, range_end = (min_value, max_value)
        new_element_idx = element_idx + 1
        if new_element_idx == len(lists[list_idx]):
            break
        new_element = lists[list_idx][new_element_idx]
        heapq.heappush(heap, (new_element, list_idx, new_element_idx))
        max_value = max(max_value, new_element)
    return (range_start, range_end)