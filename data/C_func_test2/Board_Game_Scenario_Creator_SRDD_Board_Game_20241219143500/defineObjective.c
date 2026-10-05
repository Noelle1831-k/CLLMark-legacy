void defineObjective(Objectives *objectives, char *objective) {
    if (objectives->count < MAX_OBJECTIVES) {
        snprintf(objectives->objectives[objectives->count], MAX_OBJECTIVE_LENGTH, "%s", objective);
        objectives->count++;
    } else {
        printf("Maximum number of objectives reached.\n");
    }
}