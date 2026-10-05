def __init__(self):
        '''
        Initializes the news fetcher with a dummy article database.
        '''
        self.dummy_articles = [
            {"id": "1", "title": "Tech Innovations", "source": "TechCrunch", "url": "https://techcrunch.com"},
            {"id": "2", "title": "Sports Update", "source": "ESPN", "url": "https://espn.com"},
            {"id": "3", "title": "Global Politics", "source": "BBC", "url": "https://bbc.com"}
        ]