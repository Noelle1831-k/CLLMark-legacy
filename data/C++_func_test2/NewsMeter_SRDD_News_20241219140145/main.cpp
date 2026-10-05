int main() {
    string articleTitle = "Global Warming: Myths and Realities";
    string articleContent = "Recent studies indicate a severe rise in global temperatures, caused largely by human activities...";
    string articleSource = "www.environmentalnews.com";
    NewsArticle article(articleTitle, articleContent, articleSource);
    CredibilityAnalyzer analyzer(article);
    analyzer.evaluateGrammar();
    analyzer.evaluateSourceReliability();
    analyzer.evaluateBias();
    analyzer.evaluateSentiment();
    Score score = analyzer.generateScore();
    Dashboard dashboard(score);
    dashboard.displayResults();
    return 0;
}