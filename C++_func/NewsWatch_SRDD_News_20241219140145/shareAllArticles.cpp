void SharingManager::shareAllArticles(const vector<Article>& articles) const {
    for (size_t i = 0; i < articles.size(); i++) {
        cout << "Sharing article: " << articles[i].getTitle() << endl;
    }
}