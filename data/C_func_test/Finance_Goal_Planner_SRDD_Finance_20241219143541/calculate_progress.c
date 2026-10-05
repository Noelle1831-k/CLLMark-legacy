void calculate_progress() {
    for (int i = 0; i < goal_count; i++) {
        float progress = (goals[i].current_amount / goals[i].target_amount) * 100;
        printf("Progress for goal '%s': %.2f%%\n", goals[i].name, progress);
    }
}