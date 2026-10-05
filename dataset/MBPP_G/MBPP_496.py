from heapq import nsmallest

def heap_queue_smallest(nums, n):
    return nsmallest(n, nums)