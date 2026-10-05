def add_flashcard(self, word, definition, example_sentence=None):
        '''
        Add a new flashcard to the deck.
        '''
        flashcard = Flashcard(word, definition, example_sentence)
        self.flashcards.append(flashcard)