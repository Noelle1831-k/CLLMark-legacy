from heapq import nlargest

def expensive_items(items, n):
    return nlargest(n, items, key=lambda x: x['price'])