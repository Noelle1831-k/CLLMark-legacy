def __init__(self):
        self.api_url = "https://newsapi.org/v2/top-headlines"
        self.api_key = os.getenv("NEWS_API_KEY")  # Fetch API key from environment variable