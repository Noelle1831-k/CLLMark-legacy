def fetch_articles(self):
        '''
        Fetch articles from various news sources with error handling and delays.
        '''
        print("Fetching articles...")
        urls = ["https://news.ycombinator.com/", "https://www.bbc.com/news", "https://www.cnn.com"]
        articles = []
        for url in urls:
            try:
                response = requests.get(url, timeout=10)
                if response.status_code == 200:
                    articles.append(response.text)
                    print(f"Fetched articles from {url}")
                else:
                    print(f"Failed to fetch {url}: {response.status_code}")
            except requests.RequestException as e:
                print(f"Request error for {url}: {e}")
            time.sleep(2)  # Adding delay to prevent server overload
        return articles