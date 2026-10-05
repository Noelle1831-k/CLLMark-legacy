void NewsCategorizer::categorizeArticles(vector<NewsArticle>& articles) {
    for (int i = 0; i < articles.size(); i++) {
        articles[i].category = categorizeArticle(articles[i]);
    }
}