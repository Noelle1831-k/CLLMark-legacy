void User::selectDifficulty() {
    cout << "Select Difficulty (Easy/Medium/Hard): ";
    cin >> difficulty;
    for (int i = 0; i < difficulty.size(); i++) {
        difficulty[i] = tolower(difficulty[i]);
    }
}