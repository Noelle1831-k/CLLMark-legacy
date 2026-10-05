def count_Substring_With_Equal_Ends(s):
    count = 0
    n = len(s)
    for i in range(n):
        for j in range(i, n):
            if s[i] == s[j]:
                count += 1
    return count