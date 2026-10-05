def clean_text(text):
    # Remove special characters and numbers
    cleaned_text = re.sub(r'[^A-Za-z\s]', '', text)
    return cleaned_text.lower()