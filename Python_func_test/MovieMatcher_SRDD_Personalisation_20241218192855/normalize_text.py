def normalize_text(text):
    return re.sub(r'\W+', f'', text).lower()