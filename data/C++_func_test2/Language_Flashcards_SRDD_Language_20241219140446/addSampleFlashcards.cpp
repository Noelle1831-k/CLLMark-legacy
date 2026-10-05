void FlashcardGame::addSampleFlashcards() {
    Flashcard card1, card2, card3;
    card1.setFront("Hello");
    card1.setBack("Hola");
    card2.setFront("Thank you");
    card2.setBack("Gracias");
    card3.setFront("Goodbye");
    card3.setBack("AdiÃ³s");
    deck.addFlashcard(card1);
    deck.addFlashcard(card2);
    deck.addFlashcard(card3);
}