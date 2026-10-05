vector<Article> NewsManager::filterNewsByPreferences(const UserPreferences& preferences) {
    vector<Article> filteredArticles;
    vector<Article> allArticles = fetchNews();
    for (int i = 0; i < allArticles.size(); i++) {
        if (preferences.isPreferred(allArticles[i].getCategory())) {
            filteredArticles.push_back(allArticles[i]);
        }
    }
    return filteredArticles;
}