void Summarizer::summarizeArticle(NewsArticle& article) {
    string summary = article.getSummary(150);
    cout << "Summary: " << summary << endl;
}