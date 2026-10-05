def update_news():
            for source in news_sources:
                news_data = fetcher.fetch_news(source)
                parsed_news = fetcher.parse_news(news_data)
                dashboard.display_news(parsed_news)
            Timer(interval, update_news).start()