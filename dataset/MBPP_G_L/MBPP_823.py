def check_substring(string, sample):
    pattern = '^' + re.escape(sample)
    if re.match(pattern, string):
        return 'string starts with the given substring'
    else:
        return 'string doesnt start with the given substring'