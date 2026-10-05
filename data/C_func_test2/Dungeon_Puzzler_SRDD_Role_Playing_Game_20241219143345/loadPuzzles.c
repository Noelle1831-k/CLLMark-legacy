void loadPuzzles() {
    FILE *file = fopen("puzzles.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error loading puzzles. Using default puzzles.\n");
        strcpy(puzzles[0].description, "Solve the riddle of the Sphinx.");
        strcpy(puzzles[0].solution, "man");
        strcpy(puzzles[0].hint, "Think about the stages of life.");
    } else {
        int i = 0;
        while (fscanf(file, "%255[^;];%99[^;];%255[^\n]\n", puzzles[i].description, puzzles[i].solution, puzzles[i].hint) != EOF && i < MAX_PUZZLES) {
            i++;
        }
        fclose(file);
    }
}