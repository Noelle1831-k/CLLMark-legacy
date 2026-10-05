void updateMatch() {
    int id;
    printf("Enter match ID to update: ");
    scanf("%d", &id);
    if (id < 0 || id >= match_count) {
        printf("Invalid match ID.\n");
        return;
    }
    printf("Enter new team 1 ID: ");
    scanf("%d", &matches[id].team1_id);
    printf("Enter new team 2 ID: ");
    scanf("%d", &matches[id].team2_id);
    printf("Enter new score for team 1: ");
    scanf("%d", &matches[id].score_team1);
    printf("Enter new score for team 2: ");
    scanf("%d", &matches[id].score_team2);
    printf("Enter new match date (YYYY-MM-DD): ");
    scanf("%s", matches[id].date);
    printf("Match updated successfully.\n");
}