def ncr_modp(n, r, p):
    if r > n:
        return 0
    if r == 0 or r == n:
        return 1
    numer = 1
    denom = 1
    for i in range(r):
        numer = numer * (n - i) % p
        denom = denom * (i + 1) % p
    denom_inv = pow(denom, p - 2, p)
    return numer * denom_inv % p