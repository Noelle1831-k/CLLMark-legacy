def newman_prime(n):
    def nsw_sequence():
        a, b = (1, 1)
        yield a
        yield b
        while True:
            a, b = (b, 2 * b + a)
            yield b
    def is_prime(x):
        if x < 2:
            return False
        for i in range(2, int(x ** 0.5) + 1):
            if x % i == 0:
                return False
        return True
    count = 0
    for num in nsw_sequence():
        if is_prime(num):
            count += 1
            if count == n:
                return num