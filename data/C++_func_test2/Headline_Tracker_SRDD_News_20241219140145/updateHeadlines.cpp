void NewsManager::updateHeadlines() {
    NewsFetcher fetcher;
    headlines.clear();
    for (auto &source : sources) {
        string response = fetcher.fetchFromSource(source.second);
        if (!response.empty()) {
            vector<string> sourceHeadlines = fetcher.parseJSON(response);
            headlines.insert(headlines.end(), sourceHeadlines.begin(), sourceHeadlines.end());
        }
    }
}