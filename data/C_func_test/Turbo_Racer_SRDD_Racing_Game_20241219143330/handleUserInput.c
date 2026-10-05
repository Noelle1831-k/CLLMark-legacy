void handleUserInput(Vehicle* vehicle) {
    if (_kbhit()) {
        char ch = _getch();
        switch (ch) {
            case 't':
                activateTurbo(vehicle);
                break;
            case 'n':
                deactivateTurbo(vehicle);
                break;
            case 'q':
                printf("Quitting the game...\n");
                exit(0);
            default:
                printf("Invalid input! Use 't' to activate turbo, 'n' to deactivate turbo, or 'q' to quit.\n");
                break;
        }
    }
}