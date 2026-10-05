def count_Char(s, x):
    n = len(s)
    full_repeats = 10 ** 9 // n
    total_count = s.count(x) * full_repeats
    remainder = 10 ** 9 % n
    total_count += s[0:remainder].count(x)
    return total_count
print(count_Char('abcac', 'a'))
print(count_Char('abca', 'c'))
print(count_Char('aba', 'a'))