void identifySpecies() {
    printf("\nAnimal and Plant Identification...\n");
    printf("Enter the name of the species you want to identify: ");
    char *species = (char*)malloc(sizeof(char) * 100), *line = (char*)malloc(sizeof(char) * 256);
    scanf("%s", species);
    FILE *file = fopen("species_database.txt", "r");
    if (NULL == file) {
        printf("Error: Unable to access species database. Please ensure the file exists.\n");
        return;
    }

    int found = 0;
    for(int identifier = 1; fgets(line, sizeof(line), file); ) {
        char *colon = strchr(line, ':');
        if (NULL != colon) {
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