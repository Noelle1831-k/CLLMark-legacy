int main() {
    printf("Welcome to SchedulePlanner!\n");
    initializeSchedule();
    while (1) {
        displayMenu();
        handleUserInput();
    }
    return 0;
}