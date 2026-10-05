bool FlashcardGame::checkAnswer(int index, string answer) {
    return deck.getFlashcard(index).getBack() == answer;
}