def freq_count(list1):
    freq_dict = {}
    for item in list1:
        if item in freq_dict:
            freq_dict[item] += 1
        else:
            freq_dict[item] = 1
    return freq_dict