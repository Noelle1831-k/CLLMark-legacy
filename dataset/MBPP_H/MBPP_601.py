def max_chain_length(arr, n):
    class Pair(object):
        def __init__(self, a, b):
            self.a = a
            self.b = b
    max_length = 0  
    mcl = [1 for i in range(n)]
    for i in range(1, n):
        for j in range(0, i):
            if (arr[i].a > arr[j].b and
                    mcl[i] < mcl[j] + 1):
                mcl[i] = mcl[j] + 1
    for i in range(n):
        if (max_length < mcl[i]):
            max_length = mcl[i]
    return max_length