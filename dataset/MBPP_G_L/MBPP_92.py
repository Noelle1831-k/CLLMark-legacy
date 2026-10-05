def is_undulating(n):
    if len(n) < 3:
        return False
    first, second = (n[0], n[1])
    if first == second:
        return False
    for i in range(2, len(n)):
        if n[i] != first and n[i] != second:
            return False
        if n[i] == n[i - 1]:
            return False
    return True
print(is_undulating('1212121'))
print(is_undulating('1991'))
print(is_undulating('121'))