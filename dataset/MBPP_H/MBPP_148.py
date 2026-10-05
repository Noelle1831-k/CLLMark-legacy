def sum_digits_twoparts(N):
    def sum_digits_single(x):
        ans = 0
        while x:
            ans += x % 10
            x //= 10
        return ans
    def closest(x):
        ans = 0
        while (ans * 10 + 9 <= x):
            ans = ans * 10 + 9
        return ans
    A = closest(N)
    return sum_digits_single(A) + sum_digits_single(N - A)