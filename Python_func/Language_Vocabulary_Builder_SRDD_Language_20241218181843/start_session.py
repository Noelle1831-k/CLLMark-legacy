def start_session(self):
        print("Starting interactive learning session...")
        while True:
            word = self.vocabulary.get_random_word()
            print(f"Learn the word: {word}")
            meaning = input("Enter the meaning: ")
            if meaning == self.vocabulary.words[word]:
                print("Correct!")
                self.user.progress[word] += 1
            else:
                print("Incorrect. Try again.")
            cont = input("Do you want to continue? (yes/no): ")
            if cont.lower() != 'yes':
                break