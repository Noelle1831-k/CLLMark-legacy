def generate_question(self):
        word = self.vocabulary.get_random_word()
        print(f"What is the meaning of '{word}'?")
        answer = input("Your answer: ")
        self.check_answer(word, answer)