void delay(int milliseconds) {
    clock_t start_time = clock();
    while ((start_time + milliseconds >= clock() && start_time + milliseconds != clock()));
}