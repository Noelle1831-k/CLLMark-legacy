def start_test(self):
        '''
        Starts the language proficiency test and manages user interaction
        '''
        print("Welcome to the Language Proficiency Test!")
        print(f"There are {self.total_questions} questions.")
        for idx, question in enumerate(self.questions):
            print(f"Question {idx + 1}: {question['question']}")
            answer = present_question(question)
            sanitized_answer = sanitize_input(answer)
            self.user_answers.append(sanitized_answer)
            is_correct = submit_answer(question, sanitized_answer)
            if is_correct:
                self.correct_answers += 1
        self.end_test()