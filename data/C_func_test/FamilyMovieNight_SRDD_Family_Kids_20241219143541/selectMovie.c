void selectMovie() {
    printf("Selecting movie...\n");
    printf("Available movies:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d. %s (%s, %d mins)\n", i + 1, movieLibrary[i].title, movieLibrary[i].genre, movieLibrary[i].duration);
    }
    int choice;
    printf("Enter the number of the movie you want to watch: ");
    scanf("%d", &choice);
    if (choice > 0 && choice <= movieCount) {
        printf("You have selected: %s\n", movieLibrary[choice - 1].title);
    } else {
        printf("Invalid selection.\n");
    }
}