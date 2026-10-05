vector<Article> NewsFeed::curateFeed(const User& user) const {
    vector<Article> curatedFeed;
    vector<string> preferences = user.getPreferences();
    for (size_t i = 0; i < articles.size(); i++) {
        for (size_t j = 0; j < preferences.size(); j++) {
            if (find(articles[i].getTags().begin(), articles[i].getTags().end(), preferences[j]) != articles[i].getTags().end()) {
                curatedFeed.push_back(articles[i]);
                break;
            }
        }
    }
    return curatedFeed;
}