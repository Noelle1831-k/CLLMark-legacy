int main() {
    int running = 1;
    printf("Welcome to Data Trend Analyzer Plus!\n");
    while (running) {
        displayMenu();
        handleUserSelection();
    }
    return 0;
}