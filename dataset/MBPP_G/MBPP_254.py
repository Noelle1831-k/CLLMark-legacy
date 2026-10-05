def words_ae(text):
    return [word for word in text.split() if word[0].lower() in ['a', 'e']]