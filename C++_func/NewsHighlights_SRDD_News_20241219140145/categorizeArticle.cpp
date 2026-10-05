string NewsCategorizer::categorizeArticle(const NewsArticle& article) {
    if (article.content.find("politics") != string::npos) {
        return "Politics";
    } else if (article.content.find("technology") != string::npos) {
        return "Technology";
    } else if (article.content.find("sports") != string::npos) {
        return "Sports";
    } else {
        return "General";
    }
}