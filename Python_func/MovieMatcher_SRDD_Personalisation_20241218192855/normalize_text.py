def normalize_text(text):
    return re.sub(r'\W+', '', text).lower()