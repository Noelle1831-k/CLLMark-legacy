def generate_quiz(self, language, difficulty):
        words = self.word_db.get_words(language, difficulty)
        quiz = [{'word': word} for word in words]
        random.shuffle(quiz)
        return quiz