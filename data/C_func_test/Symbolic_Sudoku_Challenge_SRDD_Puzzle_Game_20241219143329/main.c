int main() {
    Grid *grid = createGrid();
    PuzzleGenerator *generator = createPuzzleGenerator();
    Solver *solver = createSolver();
    UserInterface *ui = createUserInterface();
    generatePuzzle(generator, grid, MEDIUM);
    while (!isSolved(grid)) {
        displayGrid(ui, grid);
        char input[10];
        getUserInput(ui, input);
        if (isValidInput(grid, input)) {
            updateGrid(grid, input);
        } else {
            printf("Invalid input. Try again.\n");
        }
        if (userWantsHint(input)) {
            provideHint(solver, grid);
        }
    }
    printf("Congratulations! You've solved the puzzle.\n");
    destroyGrid(grid);
    destroyPuzzleGenerator(generator);
    destroySolver(solver);
    destroyUserInterface(ui);
    return 0;
}