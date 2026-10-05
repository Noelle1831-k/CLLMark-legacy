void Game::startGame() {
    cout << "Game started! You have " << timeLimit << " seconds to shoot as many targets as possible.\n";
    cout << "------------------------------------" << endl;
    while (currentTime < timeLimit) {
        updateGame();
        displayGameState(); 
        this_thread::sleep_for(chrono::seconds(1)); 
        currentTime++;
    }
    endGame();
}