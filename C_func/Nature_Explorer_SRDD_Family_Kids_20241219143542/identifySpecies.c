void identifySpecies() {
    printf("\nAnimal and Plant Identification...\n");
    printf("Enter the name of the species you want to identify: ");
    char species[100];
    scanf("%s", species);
    FILE *file = fopen("species_database.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to access species database. Please ensure the file exists.\n");
        return;
    }
    char line[256];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        char *colon = strchr(line, ':');
        if (colon != NULL) {
            *colon = '\0'; 
            if (strcasecmp(line, species) == 0) {
                printf("Species found: %s\n", colon + 1);
                found = 1;
                break;
            }
        }
    }
    fclose(file);
    if (!found) {
        printf("Species '%s' not found in the database. Please try another.\n", species);
    }
}