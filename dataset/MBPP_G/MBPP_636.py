def Check_Solution(a, b, c):
    if b == 0 and a == c:
        return 'Yes'
    elif a != 0 and c != 0 and (b ** 2 == 4 * a * c):
        return 'Yes'
    else:
        return 'No'