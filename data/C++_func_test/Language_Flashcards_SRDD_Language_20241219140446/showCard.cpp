void FlashcardGame::showCard(int index) {
    cout << "Flashcard " << index + 1 << ":\n";
    cout << "Front: " << deck.getFlashcard(index).getFront() << "\n";
}