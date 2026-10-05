def handle_math_problem(self):
        self.ui_manager.display_problem_types()
        problem_type = self.ui_manager.get_user_input()
        problem = None
        if problem_type == '1':
            problem = self.math_problem_generator.generate_addition_problem()
        elif problem_type == '2':
            problem = self.math_problem_generator.generate_subtraction_problem()
        elif problem_type == '3':
            problem = self.math_problem_generator.generate_multiplication_problem()
        elif problem_type == '4':
            problem = self.math_problem_generator.generate_division_problem()
        if problem:
            user_answer = self.ui_manager.get_user_input("Enter your answer: ")
            self.score_manager.update_score(problem, user_answer)