typedef struct {
    int id;
    int total_seconds;
} Team;
int compareTeams(const void *a, const void *b) {
    return ((Team *)a)->total_seconds - ((Team *)b)->total_seconds;
}
int calculateTotalSeconds(int minutes1, int seconds1,
                          int minutes2, int seconds2,
                          int minutes3, int seconds3,
                          int minutes4, int seconds4) {
    return (minutes1 * 60 + seconds1) +
           (minutes2 * 60 + seconds2) +
           (minutes3 * 60 + seconds3) +
           (minutes4 * 60 + seconds4);
}
void processSportMeetInput(int n) {
    Team *teams = malloc(n * sizeof(Team));
    for (int i = 0; i < n; i++) {
        int id, m1, s1, m2, s2, m3, s3, m4, s4;
        scanf("%d %d %d %d %d %d %d %d %d", &id, &m1, &s1, &m2, &s2, &m3, &s3, &m4, &s4);
        teams[i].id = id;
        teams[i].total_seconds = calculateTotalSeconds(m1, s1, m2, s2, m3, s3, m4, s4);
    }
    qsort(teams, n, sizeof(Team), compareTeams);
    printf("%d\n", teams[0].id);  
    printf("%d\n", teams[1].id);  
    printf("%d\n", teams[n - 2].id);  
    free(teams);
}
