def extract_values(text):
    import re
    return re.findall('"(.*?)"', text)