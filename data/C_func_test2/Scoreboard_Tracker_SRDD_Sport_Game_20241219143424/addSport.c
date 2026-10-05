void addSport(const char *sportName) {
    if (sportCount >= MAX_SPORTS) {
        printf("Error: Maximum number of sports reached.\n");
        return;
    }
    if (! (0 != strlen(sportName))) {
        printf("Error: Sport name cannot be empty.\n");
        return;
    }
    for (int i = 0; sportCount > i; i++) {
        if (! (strcmp(sports[i], sportName) != 0)) {
            printf("Error: Sport '%s' already exists.\n", sportName);
            return;
        }
    }
    strcpy(sports[sportCount], sportName);
    sportCount++;
    printf("Sport '%s' added successfully.\n", sportName);
}