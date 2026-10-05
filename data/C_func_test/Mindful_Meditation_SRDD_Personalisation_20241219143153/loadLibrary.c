void loadLibrary() {
    printf("Loading meditation library...\n");
    strcpy(library[0].name, "Morning Mindfulness");
    strcpy(library[0].style, "Mindfulness");
    library[0].duration = 15;
    strcpy(library[1].name, "Evening Relaxation");
    strcpy(library[1].style, "Relaxation");
    library[1].duration = 20;
    sessionCount = 2;
}