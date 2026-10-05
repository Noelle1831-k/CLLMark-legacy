def fetch_news(self, source):
        try:
            response = requests.get(f"https://api.news/{source}")
            response.raise_for_status()
            return response.json()
        except requests.exceptions.RequestException as e:
            self.log_error(f"Error fetching news from {source}: {e}")
            return None