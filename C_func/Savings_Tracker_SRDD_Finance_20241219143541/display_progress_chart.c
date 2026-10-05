void display_progress_chart(SavingsTracker *tracker) {
    int progress = (int)((tracker->current_savings / tracker->savings_goal) * 100);
    printf("\nProgress towards savings goal: [");
    for (int i = 0; i < progress / 5; i++) {
        printf("#");
    }
    for (int i = progress / 5; i < 20; i++) {
        printf(" ");
    }
    printf("] %d%%\n", progress);
}