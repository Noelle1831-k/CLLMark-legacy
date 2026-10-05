def is_samepatterns(colors, patterns):
    if len(colors) != len(patterns):
        return False
    sdict = {}
    for i in range(len(patterns)):
        if patterns[i] not in sdict:
            sdict[patterns[i]] = colors[i]
        elif sdict[patterns[i]] != colors[i]:
            return False
    if len(set(sdict.keys())) != len(set(sdict.values())):
        return False
    return True