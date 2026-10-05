def save_deck(self, deck):
        '''
        Save the flashcard deck to a file in JSON format.
        '''
        data = [{'word': fc.word, 'definition': fc.definition, 'example_sentence': fc.example_sentence} for fc in deck.flashcards]
        with open(self.filename, 'w') as file:
            json.dump(data, file, indent=4)