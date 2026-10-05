void exploreEcosystem() {
    printf("\nExploring ecosystems...\n");
    printf("1. Rainforest\n");
    printf("2. Desert\n");
    printf("3. Ocean\n");
    printf("4. Mountain\n");
    printf("Enter the ecosystem you want to explore: ");
    int choice;
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Returning to main menu.\n");
        while (getchar() != '\n'); 
        return;
    }
    switch (choice) {
        case 1:
            printf("Welcome to the Rainforest! Home to diverse flora and fauna.\n");
            break;
        case 2:
            printf("Welcome to the Desert! Experience the beauty of arid landscapes.\n");
            break;
        case 3:
            printf("Welcome to the Ocean! Dive into the underwater world.\n");
            break;
        case 4:
            printf("Welcome to the Mountain! Breathe in the fresh air of high altitudes.\n");
            break;
        default:
            printf("Invalid choice. Returning to main menu.\n");
    }
}