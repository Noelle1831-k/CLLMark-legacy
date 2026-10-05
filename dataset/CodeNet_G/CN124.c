typedef struct {
    char name[21];
    int points;
} Team;
int compare(const void *a, const void *b) {
    Team *teamA = (Team *)a;
    Team *teamB = (Team *)b;
    if (teamA->points != teamB->points) {
        return teamB->points - teamA->points; 
    }
    return 0;
}
void process_league() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        Team teams[10];
        for (int i = 0; i < n; i++) {
            char name[21];
            int wins, losses, draws;
            scanf("%s %d %d %d", name, &wins, &losses, &draws);
            strncpy(teams[i].name, name, 21);
            teams[i].points = wins * 3 + draws;
        }
        qsort(teams, n, sizeof(Team), compare);
        for (int i = 0; i < n; i++) {
            printf("%s,%d\n", teams[i].name, teams[i].points);
        }
        printf("\n");
    }
}