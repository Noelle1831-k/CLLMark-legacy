def are_Rotations(string1, string2):
    if len(string1) != len(string2):
        return False
    return string2 in string1 + string1