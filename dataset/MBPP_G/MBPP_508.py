def same_order(l1, l2):
    common_l1 = [x for x in l1 if x in l2]
    common_l2 = [x for x in l2 if x in l1]
    return common_l1 == common_l2