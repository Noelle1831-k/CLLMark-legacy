Flashcard FlashcardDeck::getFlashcard(int index) {
    if (index >= 0 && index < deck.size()) {
        return deck.at(index);
    } else {
        Flashcard emptyCard;
        emptyCard.setFront("Invalid Index");
        emptyCard.setBack("Invalid Index");
        return emptyCard;
    }
}