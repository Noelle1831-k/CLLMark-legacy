def generate_exercise(self):
        for category, phrases in self.user.phrasebook.categories.items():
            for phrase in phrases:
                exercise = {
                    'exercise': f"Use '{phrase.text}' in a sentence.",
                    'example': random.choice(phrase.examples)
                }
                self.exercises.append(exercise)
        random.shuffle(self.exercises)