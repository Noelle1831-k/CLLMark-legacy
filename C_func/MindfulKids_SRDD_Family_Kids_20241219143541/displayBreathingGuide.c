void displayBreathingGuide(int seconds) {
    for (int i = 1; i <= seconds; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
}