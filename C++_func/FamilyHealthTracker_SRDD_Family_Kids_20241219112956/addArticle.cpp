void HealthArticles::addArticle(const std::string& title, const std::string& content) {
    Article newArticle = {title, content};
    articles.push_back(newArticle);
}