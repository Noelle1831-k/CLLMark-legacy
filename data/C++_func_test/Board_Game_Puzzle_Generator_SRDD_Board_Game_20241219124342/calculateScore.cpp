int Puzzle::calculateScore(int timeTaken) {
    return (difficultyLevel * 100) - (timeTaken * 2);
}