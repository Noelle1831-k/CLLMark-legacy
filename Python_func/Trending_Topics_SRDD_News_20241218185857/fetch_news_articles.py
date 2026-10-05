def fetch_news_articles(self, platform):
        self._simulate_network_latency()
        return [f"News Article {i} on {platform}" for i in range(random.randint(5, 10))]