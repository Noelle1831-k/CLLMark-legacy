def main():
    logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
    display_banner()
    translator = Translator()
    detector = LanguageDetector()
    while True:
        try:
            text = get_user_input("Enter text to translate (or 'exit' to quit): ")
            if text.lower() == 'exit':
                logging.info("User exited the application.")
                print("Exiting the application. Goodbye!")
                sys.exit()
            detected_language = detector.detect_language(text)
            logging.info(f"Detected Language: {detected_language}")
            print(f"Detected Language: {detected_language}")
            target_language = get_user_input("Enter target language code (e.g., 'en' for English): ")
            translated_text = translator.translate(text, target_language)
            logging.info(f"Translated Text: {translated_text}")
            print(f"Translated Text: {translated_text}\n")
        except Exception as e:
            logging.error(f"An error occurred: {str(e)}")
            display_error("An unexpected error occurred. Please try again.")