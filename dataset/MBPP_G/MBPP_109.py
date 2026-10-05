def odd_Equivalent(s, n):
    count = 0
    for i in range(n):
        if int(s, 2) % 2 != 0:
            count += 1
        s = s[1:] + s[0]
    return count