def count_Substring_With_Equal_Ends(s):
    def check_Equality(subs):
        return (ord(subs[0]) == ord(subs[len(subs) - 1]));
    result = 0;
    n = len(s);
    for i in range(n):
        for j in range(1, n - i + 1):
            if (check_Equality(s[i:i + j])):
                result += 1;
    return result;