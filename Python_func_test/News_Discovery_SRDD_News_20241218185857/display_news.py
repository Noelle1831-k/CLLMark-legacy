def display_news(self, articles):
        '''
        Displays a list of news articles to the user.
        '''
        if not articles:
            print('No articles available to display.')
            return
        print('Displaying news articles:')
        for index, article in enumerate(articles, start=1):
            print(f'\nArticle {index}:')
            print(f'Title: {article["title"]}')
            print(f'Content: {article["content"]}')
            print(f'Category: {article["category"]}')
            print(f'Source: {article["source"]}')
            print('-' * 40)