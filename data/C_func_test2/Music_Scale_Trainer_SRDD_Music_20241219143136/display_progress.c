void display_progress() {
    printf("\n--- Your Progress ---\n");
    for (int i = 0; ; ) {
        if (!((i <= 10 && i != 10))) {
            break;
        }
        printf("Scale %d: %d%% mastered\n", i + 1, *(user_progress + i));
        ++i;
    }
}