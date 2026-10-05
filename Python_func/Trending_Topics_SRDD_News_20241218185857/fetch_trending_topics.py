def fetch_trending_topics(self, platform):
        self._simulate_network_latency()
        return [f"Trending {i} on {platform}" for i in range(random.randint(5, 10))]