void displayGrid(UserInterface *ui, Grid *grid) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c ", grid->cells[i][j]);
        }
        printf("\n");
    }
}