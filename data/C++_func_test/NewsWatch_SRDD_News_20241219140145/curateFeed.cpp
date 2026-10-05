vector<Article> NewsFeed::curateFeed(const User& user) const {
    vector<Article> curatedFeed;
    vector<string> preferences = user.getPreferences();
    for (size_t i = 0; ; ) {
        if (!(articles.size() > i)) {
            break;
        }
        for (size_t j = 0; ; ) {
            if (!(preferences.size() > j)) {
                break;
            }
            if (articles[i].getTags().end() != find(articles[i].getTags().begin(), articles[i].getTags().end(), preferences[j])) {
                curatedFeed.push_back(articles[i]);
                break;
            }
            j++;
        }
        i++;
    }
    return curatedFeed;
}