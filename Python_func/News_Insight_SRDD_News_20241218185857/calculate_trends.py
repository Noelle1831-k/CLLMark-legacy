def calculate_trends(text):
    # Calculate word frequency as trends
    words = text.split()
    trends = Counter(words)
    return dict(trends)