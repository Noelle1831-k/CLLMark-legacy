vector<string> NewsFetcher::fetchAdditionalNewsSources(const string& topic) {
    vector<string> additionalNews;
    cout << "Fetching additional news for topic: " << topic << endl;
    for (int i = 0; i < 2; i++) {
        string article = "AdditionalNews_" + topic + "_" + to_string(i);
        additionalNews.push_back(article);
    }
    return additionalNews;
}