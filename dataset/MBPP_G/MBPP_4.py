from heapq import nlargest

def heap_queue_largest(nums, n):
    return nlargest(n, nums)