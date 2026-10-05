Exercise get_exercise(char *name) {
    for (int i = 0; i < exercise_count; i++) {
        if (strcmp(exercises[i].name, name) == 0) {
            return exercises[i];
        }
    }
    Exercise empty;
    strcpy(empty.name, "Not Found");
    return empty;
}