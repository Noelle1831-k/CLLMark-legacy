def select_language(self):
        languages = list(self.word_db.words.keys())
        print("Select a language:")
        for i, lang in enumerate(languages, 1):
            print(f"{i}. {lang}")
        while True:
            try:
                choice = int(input("Enter choice: "))
                if 1 <= choice <= len(languages):
                    self.language = languages[choice - 1]
                    break
                else:
                    print("Invalid choice. Please select a valid number.")
            except ValueError:
                print("Invalid input. Please enter a number.")