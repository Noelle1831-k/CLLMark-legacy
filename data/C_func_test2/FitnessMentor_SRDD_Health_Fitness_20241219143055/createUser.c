void createUser() {
    struct User newUser;
    printf("Enter name: ");
    scanf("%s", newUser.name);
    printf("Enter age: ");
    scanf("%d", &newUser.age);
    printf("Enter gender: ");
    scanf("%s", newUser.gender);
    printf("Enter fitness goal: ");
    scanf("%s", newUser.fitnessGoal);
    printf("Enter fitness level (1-10): ");
    scanf("%d", &newUser.fitnessLevel);
    printf("Enter available equipment: ");
    scanf("%s", newUser.equipment);
    printf("Enter preferred workout duration (minutes): ");
    scanf("%d", &newUser.workoutDuration);
    users[userCount++] = newUser;
    printf("User created successfully!\n");
}