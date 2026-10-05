int main(int argc, char *argv[]) {
    Dashboard dashboard;
    printf("Welcome to the Employee Performance Tracker!\n");
    while (true) {
        dashboard.showMenu();
        dashboard.handleInput();
    }
    return 0;
}