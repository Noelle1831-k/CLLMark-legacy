void calculateScores(char *record, int *scoreA, int *scoreB) {
    *scoreA = 0;
    *scoreB = 0;
    int len = strlen(record);
    for (int i = 0; i < len; i++) {
        if (record[i] == 'A') {
            (*scoreA)++;
        } else {
            (*scoreB)++;
        }
        if ((*scoreA >= 11 || *scoreB >= 11) && abs(*scoreA - *scoreB) >= 2) {
            return;
        }
    }
}
void parseGameData() {
    char gameRecord[101];
    while (1) {
        fgets(gameRecord, sizeof(gameRecord), stdin);
        if (strcmp(gameRecord, "0\n") == 0) break;
        int scoreA = 0, scoreB = 0;
        calculateScores(gameRecord, &scoreA, &scoreB);
        printf("%d %d\n", scoreA, scoreB);
    }
}
