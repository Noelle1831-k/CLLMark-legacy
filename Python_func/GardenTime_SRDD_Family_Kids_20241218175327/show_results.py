def show_results(self):
        print(f"\nQuiz Completed! Your score: {self.score}/{len(self.quizzes)}")
        if self.score == len(self.quizzes):
            print("Excellent! You know your gardening well!")
        elif self.score >= len(self.quizzes) // 2:
            print("Good job! Keep learning to become a gardening expert!")
        else:
            print("Don't worry! Keep practicing, and you'll improve your gardening knowledge!")