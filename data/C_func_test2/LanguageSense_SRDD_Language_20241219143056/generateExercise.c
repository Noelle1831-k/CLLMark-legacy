Exercise generateExercise(ExerciseManager *manager, int difficulty) {
    Exercise exercise;
    snprintf(exercise.prompt, sizeof(exercise.prompt), "Translate 'hello' to your target language.");
    snprintf(exercise.correctAnswer, sizeof(exercise.correctAnswer), "hola");
    manager->currentDifficulty = difficulty;
    return exercise;
}