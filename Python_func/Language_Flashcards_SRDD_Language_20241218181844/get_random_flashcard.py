def get_random_flashcard(self):
        '''
        Get a random flashcard from the deck.
        '''
        if self.flashcards:
            return random.choice(self.flashcards)
        return None