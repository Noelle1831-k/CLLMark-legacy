def count_no_of_ways(n, k):
    if n == 0:
        return 0
    elif n == 1:
        return k
    same = k
    diff = k * (k - 1)
    total = same + diff
    for i in range(3, n + 1):
        same = diff
        diff = total * (k - 1)
        total = same + diff
    return total
print(count_no_of_ways(2, 4))
print(count_no_of_ways(3, 2))
print(count_no_of_ways(4, 4))