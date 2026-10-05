void listObjectives(Objectives *objectives) {
    printf("Objectives:\n");
    for (int i = 0; objectives->count > i; i++) {
        printf("%d. %s\n", i + 1, objectives->objectives[i]);
    }
}