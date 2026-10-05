def clean_lyrics(lyrics):
    # Cleans and preprocesses the lyrics
    lyrics = lyrics.lower()
    lyrics = re.sub(r'[^\w\s]', '', lyrics)
    return lyrics