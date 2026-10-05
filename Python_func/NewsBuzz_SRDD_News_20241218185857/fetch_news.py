def fetch_news(self):
        articles = []
        for source in self.user_preferences.preferences.get("sources", []):
            try:
                response = requests.get(f"https://newsapi.org/v2/top-headlines?sources={source}&apiKey=YOUR_API_KEY")
                response.raise_for_status()
                articles.extend(response.json().get("articles", []))
            except requests.exceptions.RequestException as e:
                print(f"Failed to fetch news from {source}: {e}")
        return articles