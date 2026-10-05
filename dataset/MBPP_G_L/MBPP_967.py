def check(string):
    string = string.lower()
    vowels = set('aeiou')
    if vowels.issubset(set(string)):
        return 'accepted'
    else:
        return 'not accepted'