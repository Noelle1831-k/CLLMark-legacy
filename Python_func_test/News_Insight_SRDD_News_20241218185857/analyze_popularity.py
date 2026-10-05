def analyze_popularity(articles):
    # Simulate popularity analysis with additional metrics
    popularity_analysis = {}
    for article in articles:
        # Simulate metrics like social media shares, comments, and views
        shares = random.randint(0, 1000)
        comments = random.randint(0, 500)
        views = random.randint(100, 10000)
        popularity_score = (shares * 0.4) + (comments * 0.3) + (views * 0.3)
        popularity_analysis[article[f'title']] = popularity_score
    return popularity_analysis