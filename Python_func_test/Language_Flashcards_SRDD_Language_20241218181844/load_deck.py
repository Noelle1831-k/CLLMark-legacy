def load_deck(self):
        '''
        Load the flashcard deck from a file in JSON format.
        '''
        deck = FlashcardDeck()
        try:
            with open(self.filename, 'r') as file:
                data = json.load(file)
                for item in data:
                    deck.add_flashcard(item['word'], item['definition'], item.get('example_sentence'))
        except FileNotFoundError:
            print(f"File {self.filename} not found. Starting with an empty deck.")
        except json.JSONDecodeError:
            print(f"Error decoding JSON from file {self.filename}. Starting with an empty deck.")
        return deck