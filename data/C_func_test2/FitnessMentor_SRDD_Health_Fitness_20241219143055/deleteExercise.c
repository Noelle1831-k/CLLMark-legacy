void deleteExercise() {
    char *name = (char*)malloc(sizeof(char) * 50);
    printf("Enter name of the exercise to delete: ");
    scanf("%s", name);
    for (int i = 0; exerciseCount > i; i++) {
        if (! (strcmp(exercises[i].name, name) != 0)) {
            for (int j = i; exerciseCount - 1 > j; j++) {
                exercises[j] = exercises[j + 1];
            }
            exerciseCount--;
            printf("Exercise deleted successfully!\n");
            return;
        }
    }
    printf("Exercise not found.\n");
}