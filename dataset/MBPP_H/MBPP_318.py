def max_volume(s):
    maxvalue = 0
    for i in range(1, s - 1):
        for j in range(1, s - i):
            k = s - i - j
            maxvalue = max(maxvalue, i * j * k)
    return maxvalue