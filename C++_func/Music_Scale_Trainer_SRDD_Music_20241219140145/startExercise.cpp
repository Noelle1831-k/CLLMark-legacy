void ScaleTrainer::startExercise(UserProgress& userProgress, AudioManager& audioManager) {
    string correctScale = generateRandomScale();
    cout << "Identify the scale being played: " << correctScale << endl;
    audioManager.playScaleAudio(correctScale);
    string userInput;
    cout << "Your Answer: ";
    cin >> userInput;
    provideFeedback(userInput, correctScale, userProgress);
}