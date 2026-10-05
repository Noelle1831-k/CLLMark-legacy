def fetch_articles(self):
        '''
        Fetches articles from predefined news sources.
        '''
        sources = ["source1", "source2", "source3"]
        articles = []
        for source in sources:
            articles.extend(self.fetch_from_source(source))
        return articles