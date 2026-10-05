def start(self):
        '''
        Start the user interface for interacting with the flashcard deck.
        '''
        while True:
            print("\n1. Add Flashcard")
            print("2. Remove Flashcard")
            print("3. Shuffle Deck")
            print("4. Display Random Flashcard")
            print("5. Display All Flashcards")
            print("6. Search Flashcard")
            print("7. Exit")
            choice = input("Choose an option: ")
            if choice == '1':
                word = input("Enter word: ")
                definition = input("Enter definition: ")
                example_sentence = input("Enter example sentence (optional): ")
                self.deck.add_flashcard(word, definition, example_sentence)
            elif choice == '2':
                word = input("Enter word to remove: ")
                self.deck.remove_flashcard(word)
            elif choice == '3':
                self.deck.shuffle_deck()
                print("Deck shuffled.")
            elif choice == '4':
                flashcard = self.deck.get_random_flashcard()
                if flashcard:
                    flashcard.display()
                else:
                    print("No flashcards available.")
            elif choice == '5':
                self.deck.display_all()
            elif choice == '6':
                word = input("Enter word to search: ")
                flashcard = self.deck.search_flashcard(word)
                if flashcard:
                    flashcard.display()
                else:
                    print("Flashcard not found.")
            elif choice == '7':
                break
            else:
                print("Invalid choice. Please try again.")