void calculateTeamStats() {
    printf("Calculate Team Statistics\n");
    for (int i = 0; i < team_count; i++) {
        printf("Team: %s, Established Year: %d\n", teams[i].name, teams[i].established_year);
    }
}