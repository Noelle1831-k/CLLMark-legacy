def basesnum_coresspondingnum(bases_num, index):
    return list(map(lambda x: x[0] ** x[1], zip(bases_num, index)))