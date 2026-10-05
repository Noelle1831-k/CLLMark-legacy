void processInput(char input) {
    switch (input) {
        case 'a':
            aimSniper();
            break;
        case 's':
            shootSniper();
            break;
        case 'q':
            printf("Exiting game...\n");
            break;
        default:
            printf("Invalid command!\n");
    }
}