def next_smallest_palindrome(num):
    num_str = str(num + 1)
    length = len(num_str)
    half_length = length // 2
    if length % 2 == 0:
        left_half = num_str[0:half_length]
        possible_palindrome = int(left_half + left_half[::-1])
    else:
        left_half = num_str[0:half_length + 1]
        possible_palindrome = int(left_half + left_half[-2::-1])
    if possible_palindrome > num:
        return possible_palindrome
    if length % 2 == 0:
        left_half = str(int(left_half) + 1)
        return int(left_half + left_half[::-1])
    else:
        left_half = str(int(left_half) + 1)
        return int(left_half + left_half[-2::-1])