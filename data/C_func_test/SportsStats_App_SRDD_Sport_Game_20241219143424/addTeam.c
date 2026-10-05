void addTeam() {
    if (team_count >= MAX_TEAMS) {
        printf("Team limit reached.\n");
        return;
    }
    printf("Enter team name: ");
    scanf("%s", teams[team_count].name);
    printf("Enter established year: ");
    scanf("%d", &teams[team_count].established_year);
    team_count++;
    printf("Team added successfully.\n");
}