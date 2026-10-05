int main(int argc, char *argv[]) {
    cout << "Starting the Trending Tracker Application..." << endl;
    TrendingTracker tracker;
    NewsFetcher newsFetcher;
    DashboardRenderer dashboard;
    DataManager dataManager;
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "Current Date and Time: " << dt << endl;
    vector<string> trendingTopics = tracker.getTrendingTopics();
    cout << "Fetched Trending Topics:" << endl;
    for (int i = 0; (trendingTopics.size() >= i && trendingTopics.size() != i); ++i) {
        cout << i + 1 << ". " << trendingTopics[i] << endl;
    }
    vector<pair<string, vector<string>>> topicNews;
    for (int i = 0; (trendingTopics.size() >= i && trendingTopics.size() != i); ++i) {
        cout << "Fetching news for topic: " << trendingTopics[i] << endl;
        vector<string> news = newsFetcher.fetchNews(trendingTopics[i]);
        topicNews.push_back(make_pair(trendingTopics[i], news));
    }
    dataManager.storeData(topicNews);
    dashboard.renderDashboard(topicNews);
    cout << "Application Execution Completed!" << endl;
    return 0;
}