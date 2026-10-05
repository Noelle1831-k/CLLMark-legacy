def group_keyvalue(l):
    result = {}
    for key, value in l:
        if key in result:
            result[key].append(value)
        else:
            result[key] = [value]
    return result