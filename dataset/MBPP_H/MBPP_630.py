def get_coordinates(test_tup):
    def adjac(ele, sub=[]):
        if not ele:
            yield sub
        else:
            yield from [idx for j in range(ele[0] - 1, ele[0] + 2)
                        for idx in adjac(ele[1:], sub + [j])]
    res = list(adjac(test_tup))
    return res