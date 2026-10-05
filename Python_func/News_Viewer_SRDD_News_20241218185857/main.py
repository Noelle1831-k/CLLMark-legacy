def main():
    utils.log_info("Starting News Viewer Application")
    try:
        sources = news_source.get_sources()
        utils.log_info(f"Available sources: {sources}")
        for source in sources:
            if news_source.validate_source(source):
                utils.log_info(f"Fetching news from {source}")
                raw_data = news_fetcher.fetch_news(source)
                if raw_data:
                    articles = news_fetcher.parse_news_data(raw_data)
                    news_display.display_news(articles)
                else:
                    utils.log_error(f"No data returned from {source}")
            else:
                utils.log_error(f"Invalid source: {source}")
    except Exception as e:
        utils.log_error(f"An unexpected error occurred: {e}")