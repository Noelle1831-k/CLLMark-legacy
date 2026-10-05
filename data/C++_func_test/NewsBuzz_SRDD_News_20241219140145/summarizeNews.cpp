vector<string> NewsSummarizer::summarizeNews(const vector<string>& articles, const vector<string>& preferences) {
    vector<string> summaries;
    for (size_t i = 0; i < articles.size(); i++) {
        for (size_t j = 0; j < preferences.size(); j++) {
            if (articles[i].find(preferences[j]) != string::npos) {
                summaries.push_back(createSummary(articles[i]));
                break;
            }
        }
    }
    return summaries;
}