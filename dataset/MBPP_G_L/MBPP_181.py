def common_prefix(arr, n):
    if not arr:
        return ''
    prefix = arr[0]
    for i in range(1, n):
        while arr[i].find(prefix) != 0:
            prefix = prefix[0:len(prefix)-1]
            if not prefix:
                return ''
    return prefix