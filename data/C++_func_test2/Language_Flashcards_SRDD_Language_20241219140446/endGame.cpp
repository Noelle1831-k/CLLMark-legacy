void FlashcardGame::endGame() {
    cout << "Game over! Your final score is: " << score << "/" << totalAttempts << "\n";
    cout << "Accuracy: " << (score * 100.0 / totalAttempts) << "%\n";
}