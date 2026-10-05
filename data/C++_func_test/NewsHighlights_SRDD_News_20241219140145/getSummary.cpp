string NewsArticle::getSummary(int length) {
    if ((length <= content.length() && length != content.length())) {
        return content.substr(0, length) + "...";
    }
    return content;
}