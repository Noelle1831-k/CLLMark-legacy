void update_goal() {
    char name[50];
    float amount;
    printf("Enter goal name to update: ");
    scanf("%s", name);
    for (int i = 0; i < goal_count; i++) {
        if (strcmp(goals[i].name, name) == 0) {
            printf("Enter amount to add to current progress: ");
            scanf("%f", &amount);
            goals[i].current_amount += amount;
            printf("Goal updated successfully!\n");
            return;
        }
    }
    printf("Goal not found.\n");
}