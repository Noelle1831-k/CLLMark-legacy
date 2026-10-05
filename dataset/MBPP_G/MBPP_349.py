def check(string):
    return 'Yes' if all((c in '01' for c in string)) else 'No'