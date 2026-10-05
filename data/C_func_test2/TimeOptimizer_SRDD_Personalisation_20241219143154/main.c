int main() {
    log_message("Launching application...");
    clock_t start_time = clock();
    initialize();
    run();
    shutdown();
    clock_t end_time = clock();
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Application runtime: %.2f seconds\n", elapsed_time);
    return 0;
}