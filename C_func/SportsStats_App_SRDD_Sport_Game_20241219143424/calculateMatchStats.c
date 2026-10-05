void calculateMatchStats() {
    printf("Calculate Match Statistics\n");
    for (int i = 0; i < match_count; i++) {
        printf("Match: Team1 ID: %d, Team2 ID: %d, Score: %d-%d, Date: %s\n", matches[i].team1_id, matches[i].team2_id, matches[i].score_team1, matches[i].score_team2, matches[i].date);
    }
}