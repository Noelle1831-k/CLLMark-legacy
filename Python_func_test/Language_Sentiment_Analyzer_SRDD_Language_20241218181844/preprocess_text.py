def preprocess_text(text):
    '''
    Preprocess the input text by removing special characters, converting to lowercase, and removing stop words.
    '''
    # Load stop words
    with open('stop_words.txt', 'r') as file:
        stop_words = set(file.read().splitlines())
    # Remove special characters and convert to lowercase
    text = re.sub(r'[^a-zA-Z\s]', '', text).lower()
    # Remove stop words
    words = text.split()
    filtered_words = [word for word in words if word not in stop_words]
    return ' '.join(filtered_words)