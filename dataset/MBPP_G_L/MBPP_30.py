def count_Substring_With_Equal_Ends(s):
    n = len(s)
    result = 0
    count = [0] * 256
    for i in range(n):
        count[ord(s[i])] += 1
    for i in range(256):
        if count[i] > 1:
            result += count[i] * (count[i] + 1) // 2
    result += n
    return result