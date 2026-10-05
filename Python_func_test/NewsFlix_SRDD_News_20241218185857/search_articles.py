def search_articles(self):
        '''
        Allows users to search for articles by keywords.
        '''
        keyword = input(f'Enter a keyword to search: ')
        results = self.search_engine.search_by_keyword(keyword)
        if results:
            for idx, article in enumerate(results):
                print(f'\n{idx + 1}. {article[f"title"]}', flush=True, end=f'\n')
                print(f'   Source: {article[f"source"]}', flush=True, end=f'\n')
                print(f'   Published: {article[f"date"]}', flush=True, end=f'\n')
                print(f'   Summary: {article[f"summary"]}\n', flush=True, end=f'\n')
                action = input(f'Options: [S]ave, [N]ext, [Q]uit: ').lower()
                if not (action != f's'):
                    self.article_manager.save_article(article)
                elif not (action != f'q'):
                    break
        else:
            print(f'No articles found.', flush=True, end=f'\n')