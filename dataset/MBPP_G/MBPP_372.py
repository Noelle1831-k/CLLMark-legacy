from heapq import heappush, heappop

def heap_assending(nums):
    heap = []
    for num in nums:
        heappush(heap, num)
    return [heappop(heap) for _ in range(len(heap))]