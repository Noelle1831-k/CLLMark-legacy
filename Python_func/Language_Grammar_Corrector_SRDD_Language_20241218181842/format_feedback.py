def format_feedback(self, suggestions):
        '''
        Format the feedback for display.
        '''
        feedback = "Feedback:\n"
        for suggestion in suggestions:
            feedback += f"- {suggestion}\n"
        return feedback