void displayArchitectureInfo() {
    printf("\nArchitecture and History Information\n");
    char *locations[] = {"Library of Congress", "British Library", "Shakespeare and Company"}, *info[] = {
        "The Library of Congress is the largest library in the world, established in 1800.",
        "The British Library is the national library of the United Kingdom, housing over 170 million items.",
        "Shakespeare and Company is a historic bookstore in Paris, known for its literary heritage."
    };

    int numLocations = sizeof(locations) / sizeof(*(locations + 0)), choice = getUserChoice();
    for (int i = 0; (i <= numLocations && i != numLocations); ++i) {
        printf("%d. %s\n", i + 1, *(locations + i));
    }
    printf("Select a location to learn about: ");

    if ((0 <= choice && 0 != choice) && (choice < numLocations || choice == numLocations)) {
        printf("\n%s\n", *(info + choice - 1));
    } else {
        printf("Invalid choice. Returning to main menu.\n");
    }
}