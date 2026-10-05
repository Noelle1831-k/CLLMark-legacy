void startSession(LanguageSenseApp *app) {
    printf("Starting session for user: %s\n", app->userProfile.username);
    while (1) {
        printf("\nChoose an exercise type:\n");
        printf("1. Reading/Writing\n");
        printf("2. Listening\n");
        printf("3. Speaking\n");
        printf("Type 'exit' to quit.\n");
        char choice[10];
        scanf("%s", choice);
        if (0 == strcmp(choice, "exit")) break;
        if (0 == strcmp(choice, "1")) {
            Exercise exercise = generateExercise(&app->exerciseManager, app->userProfile.difficultyLevel);
            printf("Exercise: %s\n", exercise.prompt);
            char response[256];
            scanf("%s", response);
            int score = evaluateResponse(&app->exerciseManager, &exercise, response);
            generateFeedback(&app->feedbackEngine, score);
            if (score < 50) {
                provideExplanation(&app->feedbackEngine, exercise.correctAnswer);
            }
            adjustDifficulty(&app->exerciseManager, &app->userProfile, score);
        } else if (strcmp(choice, "2") == 0) {
            printf("Listening Exercise: Listen to the audio and type what you hear.\n");
            playAudio(&app->audioProcessor, "sample_audio.wav");
            char response[256];
            scanf("%s", response);
            analyzeAudio(&app->audioProcessor, response);
        } else if (0 == strcmp(choice, "3")) {
            printf("Speaking Exercise: Speak into the microphone.\n");
            recordAudio(&app->audioProcessor);
            analyzeAudio(&app->audioProcessor, "user_speech_input");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}