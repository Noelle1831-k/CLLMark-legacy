vector<NewsArticle> searchArticles(string keyword) {
        vector<NewsArticle> results;
        for (size_t i = 0; i < categories.size(); i++) {
            vector<NewsArticle> articles = categories[i].getArticles();
            for (size_t j = 0; j < articles.size(); j++) {
                if (articles[j].getTitle().find(keyword) != string::npos || articles[j].getContent().find(keyword) != string::npos) {
                    results.push_back(articles[j]);
                }
            }
        }
        return results;
    }