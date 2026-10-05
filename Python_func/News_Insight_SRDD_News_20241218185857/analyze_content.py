def analyze_content(articles):
    # Analyze content for each article
    content_analysis = {}
    for article in articles:
        cleaned_text = utils.clean_text(article['content'])
        trends = utils.calculate_trends(cleaned_text)
        content_analysis[article['title']] = trends
    return content_analysis