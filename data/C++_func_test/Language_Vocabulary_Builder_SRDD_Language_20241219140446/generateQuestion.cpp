void generateQuestion() {
        int randomIndex = rand() % words.size();
        Word questionWord = words[randomIndex];
        cout << "Translate the word: " << questionWord.getWord() << endl;
        string userAnswer;
        cin >> userAnswer;
        if (questionWord.checkAnswer(userAnswer)) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Incorrect! The correct translation is: " << questionWord.getTranslation() << endl;
        }
    }