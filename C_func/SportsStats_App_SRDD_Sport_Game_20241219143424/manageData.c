void manageData() {
    int choice;
    while (1) {
        printf("Data Management Module\n");
        printDivider();
        printf("1. Add Player\n2. Update Player\n3. Delete Player\n4. Add Team\n5. Update Team\n6. Delete Team\n7. Add Match\n8. Update Match\n9. Delete Match\n10. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPlayer();
                break;
            case 2:
                updatePlayer();
                break;
            case 3:
                deletePlayer();
                break;
            case 4:
                addTeam();
                break;
            case 5:
                updateTeam();
                break;
            case 6:
                deleteTeam();
                break;
            case 7:
                addMatch();
                break;
            case 8:
                updateMatch();
                break;
            case 9:
                deleteMatch();
                break;
            case 10:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}