void startVirtualTour() {
    printf("\nStarting Virtual Tour...\n");
    char *locations[] = {"Library of Congress", "British Library", "Shakespeare and Company"};
    int numLocations = sizeof(locations) / sizeof(locations[0]);
    for (int i = 0; i < numLocations; i++) {
        printf("%d. %s\n", i + 1, locations[i]);
    }
    printf("Select a location to explore: ");
    int choice = getUserChoice();
    if (choice > 0 && choice <= numLocations) {
        printf("Loading 360-degree tour of %s...\n", locations[choice - 1]);
        simulateLoading();
    } else {
        printf("Invalid choice. Returning to main menu.\n");
    }
}