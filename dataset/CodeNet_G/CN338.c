typedef struct {
    int team_number;
    long score;
} Team;
int compare(const void *a, const void *b) {
    Team *teamA = (Team *)a;
    Team *teamB = (Team *)b;
    if (teamA->score != teamB->score)
        return (teamB->score - teamA->score) > 0 ? 1 : -1;
    return teamA->team_number - teamB->team_number;
}
void execute_commands(int N, int C, int commands[][3], int command_types[]) {
    Team teams[N];
    for (int i = 0; i < N; i++) {
        teams[i].team_number = i + 1;
        teams[i].score = 0;
    }
    for (int i = 0; i < C; i++) {
        if (command_types[i] == 0) {
            int t = commands[i][0] - 1;
            int p = commands[i][1];
            teams[t].score += p;
        } else if (command_types[i] == 1) {
            qsort(teams, N, sizeof(Team), compare);
            int m = commands[i][0] - 1;
            printf("%d %ld\n", teams[m].team_number, teams[m].score);
        }
    }
}
