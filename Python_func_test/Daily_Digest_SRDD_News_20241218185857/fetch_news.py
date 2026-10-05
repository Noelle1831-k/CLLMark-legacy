def fetch_news(self):
        try:
            response = requests.get("https://newsapi.org/v2/top-headlines?country=us&apiKey=YOUR_API_KEY")
            response.raise_for_status()
            return self.parse_news(response.json())  # Parse JSON data
        except requests.exceptions.RequestException as e:
            utils.log_activity(f"Failed to fetch news: {str(e)}")
            return []