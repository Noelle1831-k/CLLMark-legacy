def super_seq(X, Y, m, n):
    def super_seq_helper(X, Y, m, n, memo):
        if (m, n) in memo:
            return memo[(m, n)]
        if not m:
            return n
        if not n:
            return m
        if X[m - 1] == Y[n - 1]:
            result = 1 + super_seq_helper(X, Y, m - 1, n - 1, memo)
        else:
            result = 1 + min(super_seq_helper(X, Y, m - 1, n, memo), super_seq_helper(X, Y, m, n - 1, memo))
        memo[(m, n)] = result
        return result
    return super_seq_helper(X, Y, m, n, {})