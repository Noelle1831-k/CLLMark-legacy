void identifyPlant() {
    char userInput[MAX_NAME_LEN];
    int found = 0;
    printf("Enter the name of the plant to identify: ");
    fgets(userInput, MAX_NAME_LEN, stdin);
    userInput[strcspn(userInput, "\n")] = 0; 
    for (int i = 0; i < MAX_PLANTS; i++) {
        if (strcasecmp(userInput, plants[i].name) == 0) {
            printf("Plant found: %s\nDescription: %s\nCare Tips: %s\n", plants[i].name, plants[i].description, plants[i].careTips);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Plant not found. Try again with another name.\n");
    }
}