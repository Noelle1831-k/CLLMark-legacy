def main():
    log = logger.Logger()
    log.log_info("Application started.")
    try:
        user_prefs = preferences.UserPreferences()
        user_prefs.load_preferences()
        log.log_info("User preferences loaded successfully.")
        fetcher = news_fetcher.NewsFetcher(user_prefs)
        articles = fetcher.fetch_news()
        log.log_info(f"Fetched {len(articles)} articles.")
        summarizer_instance = summarizer.NewsSummarizer()
        summaries = summarizer_instance.summarize_all(articles)
        log.log_info("Articles summarized successfully.")
        dash = dashboard.Dashboard()
        dash.display(summaries)
        log.log_info("Summaries displayed on dashboard.")
    except Exception as e:
        log.log_error(f"An error occurred: {e}")
    log.log_info("Application finished.")