void parseNews() {
    logMessage("Parsing news articles...");
    for (int i = 0; i < articleCount; i++) {
        strcat(articles[i].content, "Parsed content from ");
        strcat(articles[i].content, articles[i].source);
    }
}