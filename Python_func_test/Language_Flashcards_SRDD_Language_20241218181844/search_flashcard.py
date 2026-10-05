def search_flashcard(self, word):
        '''
        Search for a flashcard by word.
        '''
        for flashcard in self.flashcards:
            if flashcard.word == word:
                return flashcard
        return None