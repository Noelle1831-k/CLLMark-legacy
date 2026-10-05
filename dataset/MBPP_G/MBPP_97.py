def frequency_lists(list1):
    freq_dict = {}
    for sublist in list1:
        for item in sublist:
            if item in freq_dict:
                freq_dict[item] += 1
            else:
                freq_dict[item] = 1
    return freq_dict