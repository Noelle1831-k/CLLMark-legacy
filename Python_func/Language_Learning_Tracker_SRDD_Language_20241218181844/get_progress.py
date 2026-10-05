def get_progress(self):
        return {
            "goals": self.language_goals,
            "study_time": self.study_time,
            "vocabulary": self.vocabulary,
            "grammar_knowledge": self.grammar_knowledge
        }