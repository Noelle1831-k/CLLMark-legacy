def previous_palindrome(num):
    num -= 1
    while str(num) != str(num)[::-1]:
        num -= 1
    return num