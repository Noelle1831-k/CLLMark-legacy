void Game::selectDifficulty() {
    cout << "Select Difficulty Level (1: Easy, 2: Medium, 3: Hard): ";
    cin >> difficultyLevel;
    if (difficultyLevel < 1 || difficultyLevel > 3) {
        cout << "Invalid choice. Defaulting to Easy." << endl;
        difficultyLevel = 1;
    }
}