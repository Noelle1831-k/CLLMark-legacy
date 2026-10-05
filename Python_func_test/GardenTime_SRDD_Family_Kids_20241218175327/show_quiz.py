def show_quiz(self, selected_quiz):
        '''
        Display a customized quiz based on selected topics.
        This function takes a quiz in dictionary format and prints each question.
        '''
        print("\nStarting your customized quiz...")
        for topic, question_data in selected_quiz.items():
            print(f"\nTopic: {topic}")
            print(question_data["question"])
            options = question_data["options"]
            random.shuffle(options)
            for idx, option in enumerate(options, 1):
                print(f"{idx}. {option}")
            # Get user answer
            user_answer = input("Enter the number of your answer: ")
            try:
                user_answer = int(user_answer)
                if options[user_answer - 1] == question_data["answer"]:
                    print("Correct! Well done.")
                    self.score += 1
                else:
                    print(f"Oops! The correct answer was: {question_data['answer']}")
            except (ValueError, IndexError):
                print("Invalid input. Please select a valid option by entering a number.")
        self.show_results()