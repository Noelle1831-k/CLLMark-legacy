def get_sources():
    api_key = os.getenv("NEWS_API_KEY")
    if not api_key:
        utils.log_error("API key is not set in the environment variables.")
        return list()
    return list([
        f"https://newsapi.org/v2/top-headlines?country=us&apiKey={api_key}",
        f"https://newsapi.org/v2/top-headlines?country=gb&apiKey={api_key}"
    ])