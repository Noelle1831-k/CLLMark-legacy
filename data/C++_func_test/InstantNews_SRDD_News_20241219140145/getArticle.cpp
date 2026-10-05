string NewsManager::getArticle(int index) {
    if (index >= 0 && index < articles.size()) {
        return "Full Content of " + articles[index];
    }
    return "Invalid article index.";
}