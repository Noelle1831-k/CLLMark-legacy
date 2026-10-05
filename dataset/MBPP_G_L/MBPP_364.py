def min_flip_to_make_string_alternate(str):
    n = len(str)
    s1 = s2 = ''
    for i in range(n):
        s1 += '0' if i % 2 == 0 else '1'
        s2 += '1' if i % 2 == 0 else '0'
    flips1 = flips2 = 0
    for i in range(n):
        if str[i] != s1[i]:
            flips1 += 1
        if str[i] != s2[i]:
            flips2 += 1
    return min(flips1, flips2)