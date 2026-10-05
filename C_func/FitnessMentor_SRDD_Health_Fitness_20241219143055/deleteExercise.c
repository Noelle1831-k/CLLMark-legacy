void deleteExercise() {
    char name[50];
    printf("Enter name of the exercise to delete: ");
    scanf("%s", name);
    for (int i = 0; i < exerciseCount; i++) {
        if (strcmp(exercises[i].name, name) == 0) {
            for (int j = i; j < exerciseCount - 1; j++) {
                exercises[j] = exercises[j + 1];
            }
            exerciseCount--;
            printf("Exercise deleted successfully!\n");
            return;
        }
    }
    printf("Exercise not found.\n");
}