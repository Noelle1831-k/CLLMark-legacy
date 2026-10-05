vector<Article> NewsManager::fetchNews() {
    vector<Article> articles;
    for (int i = 0; i < 5; i++) {
        int randomCategory = rand() % 3;
        string category = (randomCategory == 0) ? "Politics" : (randomCategory == 1) ? "Technology" : "Sports";
        Article article("Title " + to_string(i + 1), "Content " + to_string(i + 1), "Source " + to_string(i + 1), category);
        articles.push_back(article);
    }
    return articles;
}