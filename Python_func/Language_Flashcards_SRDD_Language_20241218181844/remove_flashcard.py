def remove_flashcard(self, word):
        '''
        Remove a flashcard from the deck by word.
        '''
        self.flashcards = [fc for fc in self.flashcards if fc.word != word]