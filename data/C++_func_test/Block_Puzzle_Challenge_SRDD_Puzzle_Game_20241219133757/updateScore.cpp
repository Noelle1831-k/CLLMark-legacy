void Game::updateScore(int linesCleared) {
    score += linesCleared * 10;
    cout << "Score: " << score << endl;
}