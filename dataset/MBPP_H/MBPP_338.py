def count_Substring_With_Equal_Ends(s):
    def check_Equality(sub):
        return (ord(sub[0]) == ord(sub[len(sub) - 1]))
    result = 0
    n = len(s)
    for i in range(n):
        for j in range(1, n - i + 1):
            if (check_Equality(s[i:i + j])):
                result += 1
    return result