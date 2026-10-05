string NewsArticle::getSummary(int length) {
    if (content.length() > length) {
        return content.substr(0, length) + "...";
    }
    return content;
}