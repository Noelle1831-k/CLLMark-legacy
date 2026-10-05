void showWateringSchedule() {
    char plantName[50];
    int found = 0;
    printf("Enter the plant name to see its watering schedule: ");
    fgets(plantName, 50, stdin);
    plantName[strcspn(plantName, "\n")] = 0; 
    for (int i = 0; MAX_PLANTS > i; i++) {
        if (strcasecmp(plantName, schedule[i].name) == 0) {
            printf("%s should be watered every %d days.\nSpecial Instructions: %s\n", schedule[i].name, schedule[i].waterInterval, schedule[i].specialInstructions);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Watering schedule for %s not found.\n", plantName);
    }
}