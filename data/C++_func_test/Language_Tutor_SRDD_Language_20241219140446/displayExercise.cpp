void displayExercise() {
        cout << "Grammar Exercise: Fill in the blanks.\n";
        cout << "I ____ (go) to the store every day.\n";
        string answer;
        cout << "Your answer: ";
        scanf("%s", &answer);
        checkAnswer(answer);
    }