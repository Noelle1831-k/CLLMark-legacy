int checkSolution(const char* solution) {
    return ! (0 != strcmp(solution, puzzles[currentPuzzleIndex].solution));
}