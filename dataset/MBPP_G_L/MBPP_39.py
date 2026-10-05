def rearange_string(S):
    from collections import Counter
    count = Counter(S)
    max_heap = [(-freq, char) for char, freq in count.items()]
    heapq.heapify(max_heap)
    prev_char = None
    prev_freq = 0
    result = []
    while max_heap or prev_freq:
        if prev_freq:
            if not max_heap:
                return ''
            heapq.heappush(max_heap, (prev_freq, prev_char))
        freq, char = heapq.heappop(max_heap)
        result.append(char)
        prev_char, prev_freq = (char, freq + 1)
    return ''.join(result) if len(result) == len(S) else ''