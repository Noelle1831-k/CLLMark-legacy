void simulateLoading() {
    printf("Loading");
    for (int i = 0; i < 5; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
}