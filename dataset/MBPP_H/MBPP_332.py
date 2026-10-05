def char_frequency(str1):
    dict = {}
    for n in str1:
        if n in dict:
            dict[n] += 1
        else:
            dict[n] = 1
    return dict