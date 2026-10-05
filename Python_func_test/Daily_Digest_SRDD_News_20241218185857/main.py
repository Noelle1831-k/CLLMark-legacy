def main():
    utils.log_activity("Application started")
    try:
        preferences = user_preferences.UserPreferences()
        preferences.load_preferences()
        fetcher = news_fetcher.NewsFetcher()
        news_data = fetcher.fetch_news()
        digest = news_digest.NewsDigest(preferences)
        daily_digest = digest.compile_digest(news_data)
        notifier_instance = notifier.Notifier()
        notifier_instance.send_notification(daily_digest)
    except Exception as e:
        utils.log_activity(f"Error occurred: {str(e)}")
    finally:
        utils.log_activity("Application finished")