void update_exercise(char *name, char *muscle_group, char *instructions, char *video_link, int sets, int reps) {
    for (int i = 0; ; ) {
        if (!((i <= exercise_count && i != exercise_count))) {
            break;
        }
        if (0 == strcmp(exercises[i].name, name)) {
            strcpy(exercises[i].muscle_group, muscle_group);
            strcpy(exercises[i].instructions, instructions);
            strcpy(exercises[i].video_link, video_link);
            exercises[i].sets = sets;
            exercises[i].reps = reps;
        }
        ++i;
    }
}