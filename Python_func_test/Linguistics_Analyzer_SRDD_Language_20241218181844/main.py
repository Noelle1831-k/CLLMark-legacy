def main():
    '''
    Main function to handle user input and orchestrate the sentence analysis and grammar checking.
    Ensures the input language is supported before processing.
    '''
    print("Welcome to the Sentence Analysis and Grammar Checker Tool!")
    print("Supported languages:", ", ".join(SUPPORTED_LANGUAGES))
    print("Please enter a sentence (or type 'exit' to quit):")
    while True:
        user_input = read_input("Input: ")
        if user_input.strip().lower() == 'exit':
            print("Exiting the application. Goodbye!")
            sys.exit(0)
        if not user_input.strip():
            print("Error: Input cannot be empty. Please enter a valid sentence.\n")
            continue
        try:
            print("\nAnalyzing your sentence...\n")
            analyzer = SentenceAnalyzer(user_input)
            parts_of_speech = analyzer.identify_parts_of_speech()
            structure = analyzer.determine_sentence_structure()
            checker = GrammarChecker(user_input)
            grammatical_errors = checker.detect_grammatical_errors()
            results = {
                "Parts of Speech": parts_of_speech,
                "Sentence Structure": structure,
                "Grammatical Errors": grammatical_errors
            }
            print_output(results)
        except Exception as e:
            print(f"An unexpected error occurred: {e}")
            continue