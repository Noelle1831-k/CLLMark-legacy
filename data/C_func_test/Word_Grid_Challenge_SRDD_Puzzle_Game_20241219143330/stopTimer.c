void stopTimer() {
    clock_t end_time = clock();
    double elapsed = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time elapsed: %.2f seconds\n", elapsed);
}