def is_triangleexists(a, b, c):
    if (a != 0 and b != 0 and c != 0 and (a + b + c) == 180):
        if ((a + b) > c and (b + c) > a and (a + c) > b):
            return True
        else:
            return False
    else:
        return False