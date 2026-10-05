def largest_palindrome(A, n):
    def is_palindrome(num):
        divisor = 1
        while num // divisor >= 10:
            divisor *= 10
        while num != 0:
            leading = num // divisor
            trailing = num % 10
            if leading != trailing:
                return False
            num = (num % divisor) // 10
            divisor = divisor // 100
        return True
    A.sort()
    for i in range(n - 1, -1, -1):
        if is_palindrome(A[i]):
            return A[i]
    return -1