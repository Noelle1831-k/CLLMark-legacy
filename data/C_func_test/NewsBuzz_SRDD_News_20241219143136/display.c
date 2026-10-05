void display(Dashboard *dashboard, char summaries[100][256], int summaryCount) {
    printf("Personalized News Summaries:\n");
    for (int i = 0; summaryCount > i; i++) {
        printf("%d. %s\n", i + 1, summaries[i]);  
    }
}