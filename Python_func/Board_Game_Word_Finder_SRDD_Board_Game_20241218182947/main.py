def main():
    '''
    Main driver function for the application.
    This function sets up the WordFinder and starts the user interaction loop.
    '''
    print("Welcome to the Word Finder Application!")
    # Initialize required classes
    input_handler = InputHandler()
    dictionary_manager = DictionaryManager()
    word_finder = WordFinder(dictionary_manager)
    # Load the dictionary of valid words
    try:
        dictionary_manager.load_dictionary()
    except FileNotFoundError as e:
        print(e)
        sys.exit(1)
    # Main loop
    while True:
        # Get letters from the user
        letters = input_handler.get_input()
        if not letters:
            print("Invalid input, please provide a set of letters.")
            continue
        # Find and display valid words
        valid_words = word_finder.find_words(letters)
        if valid_words:
            print(f"Valid words formed from '{letters}':")
            for word in sorted(valid_words):
                print(f"- {word}")
        else:
            print(f"No valid words can be formed from '{letters}'.")
        # Ask if the user wants to continue
        if not input_handler.ask_continue():
            print("Thank you for using the Word Finder. Goodbye!")
            sys.exit()