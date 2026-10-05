def count_elim(num):
    count = 0
    for item in num:
        if isinstance(item, tuple):
            break
        count += 1
    return count