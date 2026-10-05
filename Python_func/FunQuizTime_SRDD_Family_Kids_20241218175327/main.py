def main():
    '''
    Initializes the quiz application, loads quizzes, and manages user interaction.
    '''
    quiz_manager = QuizManager()
    visuals = Visuals()
    quizzes = quiz_manager.load_quizzes()
    subjects = ['math', 'science', 'history', 'language arts', 'general knowledge']
    difficulties = ['easy', 'medium', 'hard']
    subject = get_valid_input("Choose a subject (math, science, history, language arts, general knowledge): ", subjects)
    difficulty = get_valid_input("Choose a difficulty level (easy, medium, hard): ", difficulties)
    selected_quiz = quiz_manager.select_quiz(subject, difficulty)
    if selected_quiz:
        selected_quiz.start_quiz(visuals)
    else:
        print("No quiz available for the selected subject and difficulty.")