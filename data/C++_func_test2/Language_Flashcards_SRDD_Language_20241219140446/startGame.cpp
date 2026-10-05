void FlashcardGame::startGame() {
    if (deck.getDeckSize() == 0) {
        cout << "No flashcards available. Adding sample flashcards...\n";
        addSampleFlashcards();
    }
    deck.shuffleDeck();
    score = 0;
    totalAttempts = 0;
    string userAnswer;
    for (int i = 0; i < deck.getDeckSize(); ++i) {
        showCard(i);
        cout << "Your answer: ";
        getline(cin, userAnswer);
        if (checkAnswer(i, userAnswer)) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Incorrect. The correct answer was: " << deck.getFlashcard(i).getBack() << "\n";
        }
        totalAttempts++;
    }
    endGame();
}