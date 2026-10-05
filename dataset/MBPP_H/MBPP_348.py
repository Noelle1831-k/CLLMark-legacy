def find_ways(M):
    def bin_coff(n, r):
        val = 1
        if (r > (n - r)):
            r = (n - r)
        for i in range(0, r):
            val *= (n - i)
            val //= (i + 1)
        return val
    n = M
    a = bin_coff(2 * n, n)
    b = a // (n + 1)
    return (b)