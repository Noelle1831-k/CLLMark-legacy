def merge_sort(x):
    def merge(a, b):
        c = []
        while len(a) != 0 and len(b) != 0:
            if a[0] < b[0]:
                c.append(a[0])
                a = a[1:]
            else:
                c.append(b[0])
                b = b[1:]
        if len(a) == 0:
            c += b
        else:
            c += a
        return c
    if len(x) == 0 or len(x) == 1:
        return x
    else:
        middle = len(x) // 2
        a = merge_sort(x[:middle])
        b = merge_sort(x[middle:])
        return merge(a, b)