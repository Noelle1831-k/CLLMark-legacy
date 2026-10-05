void updateTeam() {
    int id;
    printf("Enter team ID to update: ");
    scanf("%d", &id);
    if (id < 0 || id >= team_count) {
        printf("Invalid team ID.\n");
        return;
    }
    printf("Enter new team name: ");
    scanf("%s", teams[id].name);
    printf("Enter new established year: ");
    scanf("%d", &teams[id].established_year);
    printf("Team updated successfully.\n");
}