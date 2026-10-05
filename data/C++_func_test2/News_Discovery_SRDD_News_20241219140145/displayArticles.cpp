void UIManager::displayArticles(const vector<Article>& articles) {
    cout << "Found " << articles.size() << " articles:" << endl;
    for (size_t i = 0; i < articles.size(); i++) {
        articles[i].display();
        cout << endl;
    }
}