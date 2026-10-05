def fetch_news(self):
        response = requests.get(self.api_url, params={"apiKey": self.api_key, "country": "us"})
        if response.status_code == 200:
            return response.json().get("articles", [])
        return []