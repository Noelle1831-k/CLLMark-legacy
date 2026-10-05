typedef struct {
    int id;
    int score;
} Team;
int compareScores(const void *a, const void *b) {
    Team *teamA = (Team *)a;
    Team *teamB = (Team *)b;
    return teamB->score - teamA->score;
}
int findTeamRank(Team teams[], int teamCount, int queryId) {
    int rank = 1, currentScore = -1;
    for (int i = 0; i < teamCount; i++) {
        if (teams[i].score != currentScore) {
            rank = i + 1;
            currentScore = teams[i].score;
        }
        if (teams[i].id == queryId) {
            return rank;
        }
    }
    return -1; 
}