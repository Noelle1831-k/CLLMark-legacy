void setTactics() {
    printf("\n===== SET TACTICS =====\n");
    printf("1. Aggressive\n");
    printf("2. Defensive\n");
    printf("3. Balanced\n");
    printf("Select a strategy: ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Aggressive strategy selected.\n");
            currentTactic = 1;
            break;
        case 2:
            printf("Defensive strategy selected.\n");
            currentTactic = 2;
            break;
        case 3:
            printf("Balanced strategy selected.\n");
            currentTactic = 3;
            break;
        default:
            printf("Invalid choice. Defaulting to Balanced.\n");
            currentTactic = 3;
    }
}