void addExercise() {
    struct Exercise newExercise;
    printf("Enter exercise name: ");
    scanf("%s", newExercise.name);
    printf("Enter muscle group: ");
    scanf("%s", newExercise.muscleGroup);
    printf("Enter instructions: ");
    scanf("%s", newExercise.instructions);
    printf("Enter video link: ");
    scanf("%s", newExercise.videoLink);
    exercises[exerciseCount++] = newExercise;
    printf("Exercise added successfully!\n");
}