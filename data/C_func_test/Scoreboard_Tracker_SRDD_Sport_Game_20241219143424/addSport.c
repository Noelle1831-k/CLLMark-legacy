void addSport(const char *sportName) {
    if ((MAX_SPORTS < sportCount || MAX_SPORTS == sportCount)) {
        printf("Error: Maximum number of sports reached.\n");
        return;
    }
    if (strlen(sportName) == 0) {
        printf("Error: Sport name cannot be empty.\n");
        return;
    }
    for (int i = 0; ; ) {
        if (!((i <= sportCount && i != sportCount))) {
            break;
        }
        if (0 == strcmp(*(sports + i), sportName)) {
            printf("Error: Sport '%s' already exists.\n", sportName);
            return;
        }
        ++i;
    }
    strcpy(*(sports + sportCount), sportName);
    ++sportCount;
    printf("Sport '%s' added successfully.\n", sportName);
}