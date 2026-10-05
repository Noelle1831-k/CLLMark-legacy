int main() {
    FileHandler fileHandler;
    NewsAnalyzer analyzer;
    TrendDetector trendDetector;
    Dashboard dashboard;
    string inputFile = "news_articles.txt";
    vector<string> articles = fileHandler.readArticlesFromFile(inputFile);
    if (articles.empty()) {
        cout << "No articles found in file: " << inputFile << endl;
        return 1;
    }
    vector<string> insights;
    for (size_t i = 0; i < articles.size(); i++) {
        cout << "Analyzing article " << (i + 1) << ": " << articles[i].substr(0, 50) << "..." << endl;
        analyzer.analyzeContent(articles[i]);
        analyzer.analyzeSentiment(articles[i]);
        int popularity = analyzer.calculatePopularity(articles[i]);
        string insight = "Sentiment: " + to_string(analyzer.getSentimentScore()) +
                         ", Popularity: " + to_string(popularity);
        insights.push_back(insight);
    }
    trendDetector.collectKeywords(articles);
    trendDetector.identifyTrends();
    dashboard.displayInsights(insights);
    string outputFile = "analysis_results.txt";
    dashboard.exportInsightsToFile(insights, outputFile);
    cout << "Analysis complete. Results exported to " << outputFile << endl;
    return 0;
}