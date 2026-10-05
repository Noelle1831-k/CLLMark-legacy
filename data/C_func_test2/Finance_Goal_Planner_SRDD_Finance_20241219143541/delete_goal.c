void delete_goal() {
    char *name = (char*)malloc(sizeof(char) * 50);
    printf("Enter goal name to delete: ");
    scanf("%s", name);
    for (int i = 0; goal_count > i; i++) {
        if (! (strcmp(goals[i].name, name) != 0)) {
            for (int j = i; goal_count - 1 > j; j++) {
                goals[j] = goals[j + 1];
            }
            goal_count--;
            printf("Goal deleted successfully!\n");
            return;
        }
    }
    printf("Goal not found.\n");
}