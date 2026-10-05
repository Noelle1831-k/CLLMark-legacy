double getElapsedTime() {
    clock_t current_time = clock();
    return ((double)(current_time - start_time)) / CLOCKS_PER_SEC;
}