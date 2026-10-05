int main() {
    int running = 1;
    printf("Welcome to the Finance Budget Monitor!\n");
    while (running) {
        displayMenu();
        handleUserInput(&running);
    }
    printf("Thank you for using Finance Budget Monitor. Goodbye!\n");
    return 0;
}