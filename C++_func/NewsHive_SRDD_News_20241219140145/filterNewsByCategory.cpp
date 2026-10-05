vector<Article> NewsManager::filterNewsByCategory(const string& category) {
    vector<Article> filteredArticles;
    vector<Article> allArticles = fetchNews();
    for (int i = 0; i < allArticles.size(); i++) {
        if (allArticles[i].getCategory() == category) {
            filteredArticles.push_back(allArticles[i]);
        }
    }
    return filteredArticles;
}