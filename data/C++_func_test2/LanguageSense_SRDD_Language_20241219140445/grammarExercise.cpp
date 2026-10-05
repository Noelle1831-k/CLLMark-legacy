void grammarExercise() {
        Exercise exercise = Exercise("Grammar", user.getDifficultyLevel());
        exercise.generateExercise(database);
        string userAnswer;
        cout << "Enter your answer: ";
        cin >> userAnswer;
        bool isCorrect = exercise.evaluateAnswer(userAnswer);
        feedback.generateFeedback(isCorrect);
        if (!isCorrect) {
            feedback.provideExplanation();
        }
        storeExerciseResult("Grammar", userAnswer, isCorrect);
    }