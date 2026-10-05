def __init__(self):
        self.fetcher = NewsFetcher()
        self.updater = NewsUpdater()
        self.dashboard = Dashboard()