void manageTeam(Team *team, TaskList *taskList) {
    int choice;
    while (1) {
        printf("\n=== Manage Team ===\n");
        printf("1. Add Team Member\n");
        printf("2. List Team Members\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addTeamMember(team);
                break;
            case 2:
                listTeamMembers(team);
                break;
            case 3:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}