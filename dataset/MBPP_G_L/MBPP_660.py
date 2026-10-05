def find_Points(l1, r1, l2, r2):
    if r1 < l2 or r2 < l1:
        return (l1, r2)
    elif l1 < l2:
        return (l1, r2)
    else:
        return (l2, r1)