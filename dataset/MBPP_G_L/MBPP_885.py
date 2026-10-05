def is_Isomorphic(str1, str2):
    if len(str1) != len(str2):
        return False
    mapping_str1 = {}
    mapping_str2 = {}
    for char1, char2 in zip(str1, str2):
        if char1 in mapping_str1 and mapping_str1[char1] != char2 or (char2 in mapping_str2 and mapping_str2[char2] != char1):
            return False
        mapping_str1[char1] = char2
        mapping_str2[char2] = char1
    return True