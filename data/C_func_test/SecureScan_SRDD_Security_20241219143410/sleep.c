void sleep(int seconds) {
    printf("Sleeping for %d seconds...\n", seconds);
    for (int i = 0; i < seconds; i++) {
        printf(".");
        fflush(stdout);
        for (int j = 0; j < 100000000; j++); 
    }
    printf("\n");
}