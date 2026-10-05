def modified_encode(alist):
    result = []
    i = 0
    while i < len(alist):
        count = 1
        while i + 1 < len(alist) and alist[i] == alist[i + 1]:
            count += 1
            i += 1
        if count > 1:
            result.append([count, alist[i]])
        else:
            result.append(alist[i])
        i += 1
    return result