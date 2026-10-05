import re

def camel_to_snake(text):
    return re.sub('(?<!^)(?=[A-Z])', '_', text).lower()