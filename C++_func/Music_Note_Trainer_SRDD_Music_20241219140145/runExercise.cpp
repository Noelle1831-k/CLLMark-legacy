void runExercise() {
        int level;
        cout << "Select difficulty level (1-Easy, 2-Medium, 3-Hard): ";
        cin >> level;
        difficulty.setDifficulty(level);
        Exercise exercise;
        exercise.generateExercise(difficulty.getDifficulty());
        exercise.displayExercise();
        string answer;
        cout << "Enter your answer: ";
        cin >> answer;
        if (exercise.checkAnswer(answer)) {
            cout << "Correct!" << endl;
            currentUser.updateScore(10);
        } else {
            cout << "Incorrect. Try again next time!" << endl;
        }
    }