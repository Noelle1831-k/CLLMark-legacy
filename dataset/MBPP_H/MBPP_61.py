def count_Substrings(s, n):
    from collections import defaultdict
    count, total = 0, 0
    mp = defaultdict(lambda: 0)
    mp[0] += 1
    for i in range(n):
        total += ord(s[i]) - ord('0')
        count += mp[total - (i + 1)]
        mp[total - (i + 1)] += 1
    return count