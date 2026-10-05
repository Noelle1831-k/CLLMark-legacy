string NewsSummarizer::createSummary(const string& article) {
    return "Summary: " + article.substr(0, article.find(".") + 1);
}