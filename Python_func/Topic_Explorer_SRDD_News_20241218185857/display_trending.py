def display_trending(self):
        self.fetch_trending()
        print("Trending Topics:")
        for topic in self.trending_topics:
            print(f"- {topic}")