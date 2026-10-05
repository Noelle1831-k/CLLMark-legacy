def nth_super_ugly_number(n, primes):
    import heapq
    ugly_numbers = [1]
    indices = [0] * len(primes)
    values = list(primes)
    heapq.heapify(values)
    for _ in range(1, n):
        next_ugly = heapq.heappop(values)
        ugly_numbers.append(next_ugly)
        for i in range(len(primes)):
            if indices[i] < len(ugly_numbers) and primes[i] * ugly_numbers[indices[i]] == next_ugly:
                indices[i] += 1
            heapq.heappush(values, primes[i] * ugly_numbers[indices[i]])
    return ugly_numbers[-1]