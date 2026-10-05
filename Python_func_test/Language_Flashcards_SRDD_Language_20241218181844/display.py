def display(self):
        '''
        Display the word, its definition, and an example sentence if available.
        '''
        print(f"Word: {self.word}")
        print(f"Definition: {self.definition}")
        if self.example_sentence:
            print(f"Example: {self.example_sentence}")