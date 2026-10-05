def min_flip_to_make_string_alternate(str):
    def make_flip(ch):
        return '1' if (ch == '0') else '0'
    def get_flip_with_starting_charcter(s, expected):
        flip_count = 0
        for i in range(len(s)):
            if (s[i] != expected):
                flip_count += 1
            expected = make_flip(expected)
        return flip_count
    return min(get_flip_with_starting_charcter(str, '0'), get_flip_with_starting_charcter(str, '1'))