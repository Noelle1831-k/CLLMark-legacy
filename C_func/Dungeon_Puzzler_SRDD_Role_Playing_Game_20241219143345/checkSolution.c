int checkSolution(const char* solution) {
    return strcmp(solution, puzzles[currentPuzzleIndex].solution) == 0;
}