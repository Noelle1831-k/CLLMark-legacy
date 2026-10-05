void add_goal() {
    if (goal_count >= 100) {
        printf("Goal limit reached. Cannot add more goals.\n");
        return;
    }
    Goal new_goal;
    printf("Enter goal name: ");
    scanf("%s", new_goal.name);
    printf("Enter target amount: ");
    scanf("%f", &new_goal.target_amount);
    new_goal.current_amount = 0;
    goals[goal_count++] = new_goal;
    printf("Goal added successfully!\n");
}