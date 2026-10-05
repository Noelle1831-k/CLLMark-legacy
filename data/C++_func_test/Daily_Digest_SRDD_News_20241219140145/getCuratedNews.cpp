vector<NewsArticle> NewsManager::getCuratedNews(const UserPreferences& preferences) const {
    vector<NewsArticle> curated;
    vector<string> preferredCategories = preferences.getPreferences();
    for (size_t i = 0; i < articles.size(); ++i) {
        if (find(preferredCategories.begin(), preferredCategories.end(), articles[i].getCategory()) != preferredCategories.end()) {
            curated.push_back(articles[i]);
        }
    }
    return curated;
}