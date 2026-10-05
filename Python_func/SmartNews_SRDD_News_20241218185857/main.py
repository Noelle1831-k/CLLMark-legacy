def main():
    # Initialize user and load preferences
    current_user = user.User()
    current_user.load_user_preferences()
    # Fetch news articles
    articles = news.fetch_news()
    # Filter articles based on user preferences
    filtered_articles = news.filter_news_by_preferences(articles, current_user.preferences)
    # Initialize recommendation engine and train model
    recommender = recommendation.RecommendationEngine()
    recommender.train_model(filtered_articles)
    # Generate recommendations
    recommendations = recommender.generate_recommendations(current_user.preferences, filtered_articles)
    # Display recommendations
    for article in recommendations:
        print(f"Title: {article.title}\nSummary: {article.summary}\n")