void updateExercise() {
    char name[50];
    printf("Enter name of the exercise to update: ");
    scanf("%s", name);
    for (int i = 0; i < exerciseCount; i++) {
        if (strcmp(exercises[i].name, name) == 0) {
            printf("Enter new muscle group: ");
            scanf("%s", exercises[i].muscleGroup);
            printf("Enter new instructions: ");
            scanf("%s", exercises[i].instructions);
            printf("Enter new video link: ");
            scanf("%s", exercises[i].videoLink);
            printf("Exercise updated successfully!\n");
            return;
        }
    }
    printf("Exercise not found.\n");
}