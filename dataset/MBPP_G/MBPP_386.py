def swap_count(s):
    open_count = 0
    swap_count = 0
    imbalance = 0
    for char in s:
        if char == '[':
            open_count += 1
            if imbalance > 0:
                swap_count += imbalance
                imbalance -= 1
        else:
            open_count -= 1
            if open_count < 0:
                imbalance += 1
                open_count = 0
    return swap_count