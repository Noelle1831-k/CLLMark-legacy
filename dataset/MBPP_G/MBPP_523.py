def check_string(str1):
    checks = [(lambda s: any((x.isupper() for x in s)), 'String must have 1 upper case character.'), (lambda s: any((x.islower() for x in s)), 'String must have 1 lower case character.'), (lambda s: any((x.isdigit() for x in s)), 'String must have 1 number.'), (lambda s: len(s) >= 8, 'String length should be atleast 8.')]
    failed_checks = [message for check, message in checks if not check(str1)]
    return failed_checks if failed_checks else ['Valid string.']