def decode_list(alist):
    result = []
    for item in alist:
        if isinstance(item, list) and len(item) == 2:
            result.extend([item[1]] * item[0])
        else:
            result.append(item)
    return result