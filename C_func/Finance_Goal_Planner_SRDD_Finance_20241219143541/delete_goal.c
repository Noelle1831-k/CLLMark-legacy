void delete_goal() {
    char name[50];
    printf("Enter goal name to delete: ");
    scanf("%s", name);
    for (int i = 0; i < goal_count; i++) {
        if (strcmp(goals[i].name, name) == 0) {
            for (int j = i; j < goal_count - 1; j++) {
                goals[j] = goals[j + 1];
            }
            goal_count--;
            printf("Goal deleted successfully!\n");
            return;
        }
    }
    printf("Goal not found.\n");
}