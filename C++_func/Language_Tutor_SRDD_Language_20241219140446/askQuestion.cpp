void askQuestion() {
        cout << "Quiz: Choose the correct answer.\n";
        cout << "What is the capital of France?\n";
        cout << "a) Berlin\nb) Madrid\nc) Paris\nd) Rome\n";
        char answer;
        cout << "Your answer (a-d): ";
        cin >> answer;
        checkAnswer(answer);
    }