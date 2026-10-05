def fetch_articles(self):
        # Simulate fetching articles from an API
        response = requests.get("https://newsapi.org/v2/everything?q=technology&apiKey=YOUR_API_KEY")
        return response.json()