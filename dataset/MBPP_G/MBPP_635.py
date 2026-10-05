def heap_sort(iterable):
    import heapq
    heap = []
    for value in iterable:
        heapq.heappush(heap, value)
    return [heapq.heappop(heap) for _ in range(len(heap))]