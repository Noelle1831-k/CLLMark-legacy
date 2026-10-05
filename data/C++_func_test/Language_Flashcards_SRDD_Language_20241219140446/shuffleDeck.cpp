void FlashcardDeck::shuffleDeck() {
    srand((unsigned int)time(0));
    for (int i = deck.size() - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        Flashcard temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}