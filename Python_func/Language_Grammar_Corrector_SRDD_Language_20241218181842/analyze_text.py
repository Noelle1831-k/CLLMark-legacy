def analyze_text(self, text):
        '''
        Analyze the given text for grammatical errors and provide feedback.
        '''
        parsed_text = self.parser.parse_sentence(text)
        errors = self.identify_errors(parsed_text)
        feedback = self.provide_feedback(errors)
        self.ui.display_feedback(feedback)