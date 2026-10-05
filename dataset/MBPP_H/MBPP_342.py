def find_minimum_range(lists):
    from heapq import heappop, heappush
    class Node:
        def __init__(self, value, list_num, index):
            self.value = value
            self.list_num = list_num
            self.index = index
        def __lt__(self, other):
            return self.value < other.value
    high = float('-inf')
    p = (0, float('inf'))
    pq = []
    for i in range(len(lists)):
        heappush(pq, Node(lists[i][0], i, 0))
        high = max(high, lists[i][0])
    while True:
        top = heappop(pq)
        low = top.value
        i = top.list_num
        j = top.index
        if high - low < p[1] - p[0]:
            p = (low, high)
        if j == len(lists[i]) - 1:
            return p
        heappush(pq, Node(lists[i][j + 1], i, j + 1))
        high = max(high, lists[i][j + 1])