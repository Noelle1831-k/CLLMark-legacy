import heapq

def combine_lists(num1, num2):
    return list(heapq.merge(num1, num2))