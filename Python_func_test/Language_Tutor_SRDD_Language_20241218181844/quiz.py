def quiz():
    quizzes = tutor.quiz.get_quizzes()
    return render_template('quiz.html', quizzes=quizzes)