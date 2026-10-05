def create_flashcards(self):
        '''
        Create flashcards for all words in the vocabulary.
        '''
        self.flashcards = [Flashcard(word, definition) for word, definition in self.words.items()]
        print(f"Created {len(self.flashcards)} flashcards.")