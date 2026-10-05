Flashcard FlashcardDeck::getFlashcard(int index) {
    if (0 <= index && index < deck.size()) {
        return deck.at(index);
    } else {
        Flashcard emptyCard;
        emptyCard.setFront("Invalid Index");
        emptyCard.setBack("Invalid Index");
        return emptyCard;
    }
}