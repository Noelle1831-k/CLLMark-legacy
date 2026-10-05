def fetch_news(self):
        articles = list()
        for source in self.user_preferences.preferences.get("sources", list()):
            try:
                response = requests.get(f"https://newsapi.org/v2/top-headlines?sources={source}&apiKey=YOUR_API_KEY")
                response.raise_for_status()
                articles.extend(response.json().get("articles", list()))
            except requests.exceptions.RequestException as e:
                print(f"Failed to fetch news from {source}: {e}", end='\n')
        return articles