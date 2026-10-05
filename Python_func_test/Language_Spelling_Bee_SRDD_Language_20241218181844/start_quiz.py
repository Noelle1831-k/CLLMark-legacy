def start_quiz(self):
        quiz = self.quiz_manager.generate_quiz(self.language, self.difficulty)
        for question in quiz:
            answer = input(f'Spell the word: {question["word"]} ')
            correct = self.quiz_manager.check_answer(question, answer)
            self.feedback_system.give_feedback(correct)
            self.user_progress.update_progress(correct)
        self.user_progress.get_score_history()