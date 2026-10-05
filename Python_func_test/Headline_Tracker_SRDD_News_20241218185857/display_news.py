def display_news(self, news_list):
        print(f'Displaying news headlines:', flush=True, end=f'\n')
        for news in news_list:
            print(news, flush=True, end=f'\n')