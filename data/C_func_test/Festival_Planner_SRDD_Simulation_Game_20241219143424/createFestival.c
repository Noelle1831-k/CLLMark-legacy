void createFestival(FestivalManager *manager) {
    printf("Creating festival...\n");
    for (int i = 0; i < 10; i++) {
        if (getAvailability(&manager->artists[i])) {
            printf("Artist %s is available to perform in genre %s.\n", manager->artists[i].name, manager->artists[i].genre);
        }
    }
}