def analyze_content(tokens):
    # Analyzes the content and structure of the lyrics
    structure = {"lines": tokens.count('\n') + 1, "words": len(tokens)}
    return structure