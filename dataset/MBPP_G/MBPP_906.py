import re

def extract_date(url):
    return re.findall('/(\\d{4})/(\\d{2})/(\\d{2})/', url)