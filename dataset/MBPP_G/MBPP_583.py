def catalan_number(num):
    if num <= 1:
        return 1
    catalan = [0] * (num + 1)
    catalan[0], catalan[1] = (1, 1)
    for i in range(2, num + 1):
        for j in range(i):
            catalan[i] += catalan[j] * catalan[i - j - 1]
    return catalan[num]