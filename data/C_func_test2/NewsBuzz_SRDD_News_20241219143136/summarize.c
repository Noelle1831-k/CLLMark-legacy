void summarize(NewsSummarizer *summarizer, char articles[100][1024], int articleCount, char summaries[100][256], UserPreferences *preferences) {
    char keywords[256];
    strcpy(keywords, preferences->keywords);
    char *keyword = strtok(keywords, ", ");  
    for (int i = 0; i < articleCount; i++) {
        int matched = 0;
        char *article = articles[i];
        while (keyword != NULL) {
            if (strstr(article, keyword) != NULL) {
                strncpy(summaries[i], article, 255);
                summaries[i][255] = '\0'; 
                matched = 1;
                break;  
            }
            keyword = strtok(NULL, ", ");  
        }
        if (!matched) {
            strcpy(summaries[i], "No relevant summary available.");
        }
        strcpy(keywords, preferences->keywords);
        keyword = strtok(keywords, ", ");
    }
}