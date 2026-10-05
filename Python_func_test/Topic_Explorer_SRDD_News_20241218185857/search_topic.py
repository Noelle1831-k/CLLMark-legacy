def search_topic(self, topic):
        # Simulate searching for news articles
        self.search_results = [f"Article about {topic} {i}" for i in range(1, 6)]
        self.display_search_results()