void deleteTeam() {
    int id;
    printf("Enter team ID to delete: ");
    scanf("%d", &id);
    if (id < 0 || id >= team_count) {
        printf("Invalid team ID.\n");
        return;
    }
    for (int i = id; i < team_count - 1; i++) {
        teams[i] = teams[i + 1];
    }
    team_count--;
    printf("Team deleted successfully.\n");
}