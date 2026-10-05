void Game::startGame() {
    cout << "Welcome to the Word Grid Challenge!" << endl;
    timer.startTimer();
    grid.generateGrid(5); 
    string word;
    while (true) {
        cout << "Enter a word (or type 'exit' to quit): ";
        cin >> word;
        if (word == "exit") {
            break;
        }
        if (grid.isValidWord(word) && dictionary.isWord(word)) {
            player.addScore(word.length() * 10);
            cout << "Valid word! Score: " << player.getScore() << endl;
        } else {
            cout << "Invalid word!" << endl;
        }
    }
    timer.stopTimer();
    updateLeaderboard();
    displayLeaderboard();
}