void User::saveArticle(const NewsArticle& article) {
    savedArticles.push_back(article);
    cout << "Article saved!" << endl;
}