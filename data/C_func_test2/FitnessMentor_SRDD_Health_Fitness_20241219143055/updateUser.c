void updateUser() {
    char name[50];
    printf("Enter name of the user to update: ");
    scanf("%s", name);
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0) {
            printf("Enter new age: ");
            scanf("%d", &users[i].age);
            printf("Enter new gender: ");
            scanf("%s", users[i].gender);
            printf("Enter new fitness goal: ");
            scanf("%s", users[i].fitnessGoal);
            printf("Enter new fitness level (1-10): ");
            scanf("%d", &users[i].fitnessLevel);
            printf("Enter new available equipment: ");
            scanf("%s", users[i].equipment);
            printf("Enter new preferred workout duration (minutes): ");
            scanf("%d", &users[i].workoutDuration);
            printf("User updated successfully!\n");
            return;
        }
    }
    printf("User not found.\n");
}