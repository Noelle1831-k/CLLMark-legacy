void display_progress_bar() {
    for (int i = 0; i < goal_count; i++) {
        printf("\nGoal: %s\n", goals[i].name);
        printf("[");
        int progress = (goals[i].current_amount / goals[i].target_amount) * 50;
        for (int j = 0; j < 50; j++) {
            if (j < progress) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("] %.2f%%\n", (goals[i].current_amount / goals[i].target_amount) * 100);
    }
}