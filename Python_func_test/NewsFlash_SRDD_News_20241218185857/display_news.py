def display_news(self, news_feed):
        for category, articles in news_feed.items():
            print(f'Category: {category}', flush=True, end=f'\n')
            for article in articles:
                print(f'Title: {article[f"title"]}', flush=True, end=f'\n')
                print(f'Summary: {article[f"summary"]}\n', flush=True, end=f'\n')