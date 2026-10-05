def select_language(self):
        languages = ['English', 'Spanish', 'French', 'German']
        print("Select your target language:")
        for i, lang in enumerate(languages, 1):
            print(f"{i}. {lang}")
        choice = int(input("Enter the number of your choice: "))
        self.language = languages[choice - 1]
        self.vocab_exercise = vocabulary_exercise.VocabularyExercise(self.language)