def fetch_from_source(self, source):
        '''
        Fetches articles from a specific source.
        '''
        try:
            response = requests.get(f"https://api.newsapi.org/v2/everything?sources={source}")
            response.raise_for_status()  # Raises an HTTPError for bad responses
            data = response.json()
            return [self.parse_article(article) for article in data.get('articles', [])]
        except requests.exceptions.RequestException as e:
            print(f"Error fetching articles from {source}: {e}")
            return []
        except json.decoder.JSONDecodeError as e:
            print(f"Error decoding JSON response from {source}: {e}")
            return []