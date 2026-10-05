def display_question(self, question):
        '''
        Displays a question and its options.
        '''
        print(question.question_text)
        for idx, option in enumerate(question.options, start=1):
            print(f"{idx}. {option}")