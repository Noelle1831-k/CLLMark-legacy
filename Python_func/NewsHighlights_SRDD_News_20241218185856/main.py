def main():
    # Initialize components
    news_fetcher = NewsFetcher()
    nlp_processor = NLPProcessor()
    user_preferences = UserPreferences()
    digest_generator = DigestGenerator()
    article_manager = ArticleManager()
    # Simulate user interaction
    user_id = "user123"
    articles = news_fetcher.fetch_articles()
    # Process each article
    processed_articles = []
    for article in articles:
        summary = nlp_processor.summarize_article(article)
        category = nlp_processor.categorize_article(article)
        processed_articles.append((article, summary, category))
        print(f"Summary: {summary}\nCategory: {category}")
    # Retrieve and apply user preferences
    preferences = user_preferences.get_user_preferences(user_id)
    digest = digest_generator.generate_digest(user_id, processed_articles, preferences)
    print(f"Daily Digest for {user_id}: {digest}")
    # Simulate article management
    article_id = "article456"
    article_manager.save_article(user_id, article_id)
    article_manager.share_article(user_id, article_id, "Twitter")