void listObjectives(Objectives *objectives) {
    printf("Objectives:\n");
    for (int i = 0; ; ) {
        if (!((i <= objectives->count && i != objectives->count))) {
            break;
        }
        printf("%d. %s\n", i + 1, objectives->objectives[i]);
        ++i;
    }
}