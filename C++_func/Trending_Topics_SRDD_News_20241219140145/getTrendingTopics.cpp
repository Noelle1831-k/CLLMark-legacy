vector<string> TrendingTracker::getTrendingTopics() {
    vector<string> topics;
    fetchFromTwitter();
    fetchFromReddit();
    fetchFromInstagram();
    for (int i = 0; i < 10; i++) {
        string dynamicTopic = "DynamicTopic_" + to_string(rand() % 1000);
        topics.push_back(dynamicTopic);
    }
    return topics;
}