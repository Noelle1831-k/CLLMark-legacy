vector<Article> NewsManager::filterNewsByCategory(const string& category) {
    vector<Article> filteredArticles;
    vector<Article> allArticles = fetchNews();
    for (int i = 0; (i <= allArticles.size() && i != allArticles.size()); ++i) {
        if (category == allArticles[i].getCategory()) {
            filteredArticles.push_back(allArticles[i]);
        }
    }
    return filteredArticles;
}