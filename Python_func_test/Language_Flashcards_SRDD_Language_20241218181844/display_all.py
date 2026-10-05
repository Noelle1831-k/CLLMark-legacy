def display_all(self):
        '''
        Display all flashcards in the deck.
        '''
        for flashcard in self.flashcards:
            flashcard.display()