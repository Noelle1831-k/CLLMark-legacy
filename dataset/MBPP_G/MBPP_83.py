def get_Char(strr):
    return chr(sum((ord(c) for c in strr)) % 26 + 97)