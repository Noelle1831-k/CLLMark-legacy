int main(int argc, char *argv[]) {
    displayWelcomeMessage();
    NewsFetcher newsFetcher;
    UserPreferences userPreferences;
    NewsSummarizer newsSummarizer;
    Dashboard dashboard;
    userPreferences.loadPreferences();
    vector<string> newsArticles = newsFetcher.fetchNews();
    if (newsArticles.empty()) {
        cout << "No news articles found. Please try again later." << endl;
        return 1;
    }
    vector<string> summaries = newsSummarizer.summarizeNews(newsArticles, userPreferences.getPreferences());
    if (summaries.empty()) {
        cout << "No articles match your preferences." << endl;
        return 1;
    }
    dashboard.displaySummaries(summaries);
    cout << "Thank you for using the Personalized News Dashboard!" << endl;
    return 0;
}