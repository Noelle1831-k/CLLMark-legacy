void addMatch() {
    if (match_count >= MAX_MATCHES) {
        printf("Match limit reached.\n");
        return;
    }
    printf("Enter team 1 ID: ");
    scanf("%d", &matches[match_count].team1_id);
    printf("Enter team 2 ID: ");
    scanf("%d", &matches[match_count].team2_id);
    printf("Enter score for team 1: ");
    scanf("%d", &matches[match_count].score_team1);
    printf("Enter score for team 2: ");
    scanf("%d", &matches[match_count].score_team2);
    printf("Enter match date (YYYY-MM-DD): ");
    scanf("%s", matches[match_count].date);
    match_count++;
    printf("Match added successfully.\n");
}