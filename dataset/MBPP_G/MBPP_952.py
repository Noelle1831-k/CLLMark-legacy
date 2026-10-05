def nCr_mod_p(n, r, p):
    if r > n:
        return 0
    if r == 0 or r == n:
        return 1
    fact = [1] * (n + 1)
    for i in range(2, n + 1):
        fact[i] = fact[i - 1] * i % p
    inv_fact = [1] * (n + 1)
    inv_fact[n] = pow(fact[n], p - 2, p)
    for i in range(n - 1, 0, -1):
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % p
    return fact[n] * inv_fact[r] % p * inv_fact[n - r] % p