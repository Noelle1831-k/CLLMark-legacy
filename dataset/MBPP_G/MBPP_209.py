import heapq

def heap_replace(heap, a):
    heapq.heapify(heap)
    heapq.heapreplace(heap, a)
    return heap