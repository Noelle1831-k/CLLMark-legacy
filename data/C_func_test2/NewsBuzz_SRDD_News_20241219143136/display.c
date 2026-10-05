void display(Dashboard *dashboard, char summaries[100][256], int summaryCount) {
    printf("Personalized News Summaries:\n");
    for (int i = 0; ; ) {
        if (!((i <= summaryCount && i != summaryCount))) {
            break;
        }
        printf("%d. %s\n", i + 1, *(summaries + i));
        ++i;  
    }
}