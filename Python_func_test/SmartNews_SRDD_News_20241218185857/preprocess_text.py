def preprocess_text(text):
    # Simulate text preprocessing
    text = text.lower()
    text = re.sub(r'\W+', ' ', text)
    return text