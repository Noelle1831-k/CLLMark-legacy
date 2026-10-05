def main():
    # Load articles
    articles = article_loader.load_articles()
    # Analyze credibility
    analyzed_articles = []
    for article in articles:
        credibility_factors = credibility_analyzer.analyze(article)
        score = scoring.calculate_score(credibility_factors)
        explanation = explanation_generator.generate_explanation(credibility_factors)
        analyzed_articles.append({
            'article': article,
            'score': score,
            'explanation': explanation
        })
    # Output results
    for analyzed_article in analyzed_articles:
        print(f"Article: {analyzed_article['article']['title']}")
        print(f"Score: {analyzed_article['score']}")
        print(f"Explanation: {analyzed_article['explanation']}\n")