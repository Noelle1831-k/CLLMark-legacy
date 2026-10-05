typedef struct {
    char name;
    int wins;
    int losses;
    int draws;
} Team;
int compareTeams(const void *a, const void *b) {
    Team *teamA = (Team *)a;
    Team *teamB = (Team *)b;
    if (teamA->wins != teamB->wins) {
        return teamB->wins - teamA->wins;
    }
    if (teamA->losses != teamB->losses) {
        return teamA->losses - teamB->losses;
    }
    return 0;
}
void sortTeams(Team teams[], int n) {
    qsort(teams, n, sizeof(Team), compareTeams);
}
void processDataset(int n) {
    Team teams[10];
    for (int i = 0; i < n; i++) {
        char t;
        int score;
        teams[i].wins = teams[i].losses = teams[i].draws = 0;
        scanf(" %c", &t);
        teams[i].name = t;
        for (int j = 0; j < n - 1; j++) {
            scanf("%d", &score);
            if (score == 0) {
                teams[i].wins++;
            } else if (score == 1) {
                teams[i].losses++;
            } else {
                teams[i].draws++;
            }
        }
    }
    sortTeams(teams, n);
    for (int i = 0; i < n; i++) {
        printf("%c", teams[i].name);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}