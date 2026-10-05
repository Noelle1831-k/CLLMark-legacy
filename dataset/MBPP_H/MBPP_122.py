def smartNumber(n):
    MAX = 3000
    primes = [0] * MAX
    result = []
    for i in range(2, MAX):
        if (primes[i] == 0):
            primes[i] = 1
            j = i * 2
            while (j < MAX):
                primes[j] -= 1
                if ((primes[j] + 3) == 0 and j not in result):
                    result.append(j)
                j = j + i
    result.sort()
    return result[n - 1]