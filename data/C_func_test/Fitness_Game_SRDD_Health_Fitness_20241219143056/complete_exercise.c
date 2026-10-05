int complete_exercise(Exercise exercise) {
    printf("Performing: %s (Difficulty: %d)\n", exercise.type, exercise.difficulty);
    return rand() % exercise.difficulty == 0;  
}