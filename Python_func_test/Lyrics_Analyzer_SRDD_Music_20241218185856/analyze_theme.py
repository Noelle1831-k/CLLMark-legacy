def analyze_theme(lyrics):
    # Identifies the theme of the lyrics using spaCy
    doc = nlp(lyrics)
    themes = []
    for token in doc:
        if token.pos_ in ['NOUN', 'PROPN']:
            themes.append(token.lemma_)
    theme_frequency = Counter(themes)
    most_common_theme = theme_frequency.most_common(1)
    return {"theme": most_common_theme[0][0] if most_common_theme else "unknown"}