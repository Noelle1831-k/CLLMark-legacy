int main(int argc, char *argv[]) {
    printf("Welcome to SchedulePlanner!\n");
    initializeSchedule();
    while (1) {
        displayMenu();
        handleUserInput();
    }
    return 0;
}