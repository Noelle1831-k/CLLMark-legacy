def generate_quiz(self):
        for category, phrases in self.user.phrasebook.categories.items():
            for phrase in phrases:
                question = {
                    'question': f"What is the translation of '{phrase.text}'?",
                    'answer': phrase.text
                }
                self.questions.append(question)
        random.shuffle(self.questions)