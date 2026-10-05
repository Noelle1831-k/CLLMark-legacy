vector<string> NewsFetcher::fetchNews() {
    simulateNetworkDelay();
    vector<string> articles;
    articles.push_back("Breaking News: Market hits all-time high.");
    articles.push_back("Sports Update: Local team wins championship.");
    articles.push_back("Weather Alert: Heavy rains expected tomorrow.");
    articles.push_back("Tech News: New AI model beats benchmarks.");
    return articles;
}