def load_questions(self):
        # Simulate loading questions from a file or database
        questions = [
            ("What is the past tense of 'go'?", "went"),
            ("What is the plural of 'child'?", "children"),
            ("Fill in the blank: She ___ to the store.", "went"),
        ]
        return [Question(prompt, answer) for prompt, answer in questions]