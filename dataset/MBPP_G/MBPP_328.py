def rotate_left(list1, m, n):
    return (list1[m:] + list1[0:m])[0:len(list1) - n] if n <= len(list1) - m else list1[m:] + list1[0:m]