def Check_Vow(string, vowels):
    return sum((1 for char in string if char in vowels))