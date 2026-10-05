void ScaleTrainer::startExercise(UserProgress& userProgress, AudioManager& audioManager) {
    string correctScale = generateRandomScale();
    printf("Identify the scale being played: %s\n", correctScale.c_str());
    audioManager.playScaleAudio(correctScale);
    string userInput;
    printf("Your Answer: ");
    scanf("%s", &userInput);
    provideFeedback(userInput, correctScale, userProgress);
}