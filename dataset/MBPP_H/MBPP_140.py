def extract_singly(test_list):
    res = []
    temp = set()
    for inner in test_list:
        for ele in inner:
            if ele not in temp:
                temp.add(ele)
                res.append(ele)
    return res