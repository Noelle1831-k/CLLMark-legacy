import re

def snake_to_camel(word):
    return ''.join((x.capitalize() for x in re.split('_', word)))