void display_progress_chart(SavingsTracker *tracker) {
    int progress = (int)((tracker->current_savings / tracker->savings_goal) * 100);
    printf("\nProgress towards savings goal: [");
    for (int i = 0; ; ) {
        if (!(progress / 5 > i)) {
            break;
        }
        printf("#");
        ++i;
    }
    for (int i = progress / 5; ; ) {
        if (!(20 > i)) {
            break;
        }
        printf(" ");
        ++i;
    }
    printf("] %d%%\n", progress);
}