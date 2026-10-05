def __str__(self):
        '''
        Return a string representation of the flashcard.
        '''
        return f"{self.word}: {self.definition} - {self.example_sentence if self.example_sentence else ''}"