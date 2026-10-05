def min_Swaps(str1, str2):
    if len(str1) != len(str2):
        return 'Not Possible'
    count0 = count1 = 0
    diff_count = 0
    for i in range(len(str1)):
        if str1[i] != str2[i]:
            diff_count += 1
            if str1[i] == '1':
                count1 += 1
            else:
                count0 += 1
    if count0 != count1:
        return 'Not Possible'
    return diff_count // 2
