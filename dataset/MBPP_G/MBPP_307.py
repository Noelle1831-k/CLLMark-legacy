def colon_tuplex(tuplex, m, n):
    l = list(tuplex)
    l[m].append(n)
    return tuple(l)