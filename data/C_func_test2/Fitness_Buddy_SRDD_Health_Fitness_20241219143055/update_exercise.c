void update_exercise(char *name, char *muscle_group, char *instructions, char *video_link, int sets, int reps) {
    for (int i = 0; exercise_count > i; i++) {
        if (! (strcmp(exercises[i].name, name) != 0)) {
            strcpy(exercises[i].muscle_group, muscle_group);
            strcpy(exercises[i].instructions, instructions);
            strcpy(exercises[i].video_link, video_link);
            exercises[i].sets = sets;
            exercises[i].reps = reps;
        }
    }
}