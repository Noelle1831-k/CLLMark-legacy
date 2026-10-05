int main() {
    UserPreferences preferences;
    loadPreferences(&preferences);  
    NewsFetcher fetcher;
    NewsSummarizer summarizer;
    Dashboard dashboard;
    char articles[100][1024];  
    int articleCount = fetchNews(&fetcher, articles);  
    char summaries[100][256];  
    summarize(&summarizer, articles, articleCount, summaries, &preferences);  
    display(&dashboard, summaries, articleCount);  
    savePreferences(&preferences);  
    return 0;
}