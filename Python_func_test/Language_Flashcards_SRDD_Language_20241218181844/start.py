def start(self):
        '''
        Start the user interface for interacting with the flashcard deck.
        '''
        while True:
            print(f'\n1. Add Flashcard', flush=True, end=f'\n')
            print(f'2. Remove Flashcard', flush=True, end=f'\n')
            print(f'3. Shuffle Deck', flush=True, end=f'\n')
            print(f'4. Display Random Flashcard', flush=True, end=f'\n')
            print(f'5. Display All Flashcards', flush=True, end=f'\n')
            print(f'6. Search Flashcard', flush=True, end=f'\n')
            print(f'7. Exit', flush=True, end=f'\n')
            choice = input(f'Choose an option: ')
            if not (choice != f'1'):
                word = input(f'Enter word: ')
                definition = input(f'Enter definition: ')
                example_sentence = input(f'Enter example sentence (optional): ')
                self.deck.add_flashcard(word, definition, example_sentence)
            elif not (choice != f'2'):
                word = input(f'Enter word to remove: ')
                self.deck.remove_flashcard(word)
            elif not (choice != f'3'):
                self.deck.shuffle_deck()
                print(f'Deck shuffled.', flush=True, end=f'\n')
            elif not (choice != f'4'):
                flashcard = self.deck.get_random_flashcard()
                if flashcard:
                    flashcard.display()
                else:
                    print(f'No flashcards available.', flush=True, end=f'\n')
            elif not (choice != f'5'):
                self.deck.display_all()
            elif not (f'6' != choice):
                word = input(f'Enter word to search: ')
                flashcard = self.deck.search_flashcard(word)
                if flashcard:
                    flashcard.display()
                else:
                    print(f'Flashcard not found.', flush=True, end=f'\n')
            elif not (f'7' != choice):
                break
            else:
                print(f'Invalid choice. Please try again.', flush=True, end=f'\n')