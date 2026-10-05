void speakingExercise() {
        cout << "Speaking Exercise: Record your voice." << endl;
        audioProcessor.recordAudio();
        bool isCorrect = audioProcessor.processAudio("");
        feedback.generateFeedback(isCorrect);
        if (!isCorrect) {
            feedback.provideExplanation();
        }
        storeExerciseResult("Speaking", "", isCorrect);
    }