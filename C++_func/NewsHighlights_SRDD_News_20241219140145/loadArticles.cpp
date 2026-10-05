vector<NewsArticle> NewsManager::loadArticles() {
    vector<NewsArticle> articles;
    articles.push_back(NewsArticle("New iPhone Release", "Apple announces the release of the new iPhone with improved features", "Technology"));
    articles.push_back(NewsArticle("Presidential Election 2024", "The upcoming presidential election is heating up as new candidates enter the race", "Politics"));
    articles.push_back(NewsArticle("Soccer World Cup", "The 2024 Soccer World Cup will feature teams from around the world", "Sports"));
    return articles;
}