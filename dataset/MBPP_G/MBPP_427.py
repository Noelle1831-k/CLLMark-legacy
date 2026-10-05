import re

def change_date_format(dt):
    return re.sub('(\\d{4})-(\\d{2})-(\\d{2})', '\\3-\\2-\\1', dt)