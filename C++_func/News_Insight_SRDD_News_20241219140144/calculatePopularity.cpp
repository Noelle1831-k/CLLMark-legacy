int NewsAnalyzer::calculatePopularity(const string& article) {
    return article.length() % 100;
}