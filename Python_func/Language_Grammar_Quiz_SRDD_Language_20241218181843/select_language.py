def select_language(self):
        languages = ['English', 'Spanish', 'French']
        print("Select a language:")
        for i, lang in enumerate(languages, 1):
            print(f"{i}. {lang}")
        choice = int(input("Enter choice: "))
        self.language = languages[choice - 1]