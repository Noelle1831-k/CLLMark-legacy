void FlashcardDeck::displayDeck() {
    for (int i = 0; i < deck.size(); ++i) {
        cout << "Flashcard " << i + 1 << ":\n";
        cout << "Front: " << deck[i].getFront() << "\n";
        cout << "Back: " << deck[i].getBack() << "\n";
    }
}