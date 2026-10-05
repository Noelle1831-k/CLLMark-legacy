double calculateSimilarity(const char *genres1, const char *genres2) {
    int score = 0, total = 0;
    char genres1Copy[MAX_GENRES_LEN], genres2Copy[MAX_GENRES_LEN];
    char *token1, *token2;
    strncpy(genres1Copy, genres1, MAX_GENRES_LEN);
    strncpy(genres2Copy, genres2, MAX_GENRES_LEN);
    token1 = strtok(genres1Copy, ",");
    while (token1) {
        total++;
        token2 = strtok(genres2Copy, ",");
        while (token2) {
            if (strcmp(token1, token2) == 0) {
                score++;
                break;
            }
            token2 = strtok(NULL, ",");
        }
        token1 = strtok(NULL, ",");
    }
    return (double)score / total;
}