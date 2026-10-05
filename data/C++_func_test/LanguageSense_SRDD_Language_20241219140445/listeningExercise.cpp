void listeningExercise() {
        cout << "Listening Exercise: Listen to the audio and type what you hear." << endl;
        string userAnswer;
        cout << "Enter your answer: ";
        cin >> userAnswer;
        bool isCorrect = audioProcessor.processAudio(userAnswer);
        feedback.generateFeedback(isCorrect);
        if (!isCorrect) {
            feedback.provideExplanation();
        }
        storeExerciseResult("Listening", userAnswer, isCorrect);
    }