def generate_question(self):
        word = random.choice(self.words)
        if self.quiz_type == "Synonyms":
            self.current_question = f"What is the synonym of '{word}'?"
            self.current_answer = self.database.get_synonym(word, self.language, self.difficulty)
        elif self.quiz_type == "Antonyms":
            self.current_question = f"What is the antonym of '{word}'?"
            self.current_answer = self.database.get_antonym(word, self.language, self.difficulty)
        elif self.quiz_type == "Idioms":
            self.current_question = f"What is the meaning of the idiom '{word}'?"
            self.current_answer = self.database.get_idiom(word, self.language, self.difficulty)
        return self.current_question