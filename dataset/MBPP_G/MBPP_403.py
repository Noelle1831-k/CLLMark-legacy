import re

def is_valid_URL(url):
    pattern = re.compile('^(https?:\\/\\/)?([a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,}(\\/[^\\s]*)?$')
    return bool(pattern.match(url))