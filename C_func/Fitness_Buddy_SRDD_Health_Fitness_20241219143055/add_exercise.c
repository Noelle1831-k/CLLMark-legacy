void add_exercise(char *name, char *muscle_group, char *instructions, char *video_link, int sets, int reps) {
    Exercise exercise;
    strcpy(exercise.name, name);
    strcpy(exercise.muscle_group, muscle_group);
    strcpy(exercise.instructions, instructions);
    strcpy(exercise.video_link, video_link);
    exercise.sets = sets;
    exercise.reps = reps;
    exercises[exercise_count++] = exercise;
}