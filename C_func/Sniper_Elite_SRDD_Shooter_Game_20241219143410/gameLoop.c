void gameLoop() {
    char input;
    while (1) {
        printf("Enter command (a: aim, s: shoot, q: quit): ");
        scanf(" %c", &input);
        processInput(input);
        if (input == 'q') break;
    }
}