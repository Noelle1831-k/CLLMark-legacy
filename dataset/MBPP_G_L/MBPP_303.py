def solve(a, n):
    type1 = 0
    type2 = 0
    for i in range(n):
        for j in range(i + 1, n):
            if a[i] > a[j]:
                type1 += 1
            if a[i] < a[j]:
                type2 += 1
    return type1 == type2