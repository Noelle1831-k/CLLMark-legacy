def move_num(test_str):
    res = ''
    dig = ''
    for ele in test_str:
        if ele.isdigit():
            dig += ele
        else:
            res += ele
    return res + dig