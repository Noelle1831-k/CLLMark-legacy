def fetch_news():
    # Simulate fetching news articles from an API
    # In a real-world scenario, replace the URL with a valid news API endpoint
    url = "https://api.example.com/news"
    try:
        response = requests.get(url)
        response.raise_for_status()
        articles = response.json()
    except requests.exceptions.RequestException as e:
        print(f"Error fetching news: {e}")
        # Fallback to simulated data
        articles = [{"title": f"Article {i}", "content": f"Content of article {i}"} for i in range(1, 101)]
    return articles