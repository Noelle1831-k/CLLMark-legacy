def count_Substrings(s, n):
    count = 0
    for i in range(n):
        total = 0
        for j in range(i, n):
            total += int(s[j])
            if total == j - i + 1:
                count += 1
    return count