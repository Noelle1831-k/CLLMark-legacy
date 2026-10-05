void gameLoop() {
    bool running = true;
    char input[10]; 
    while (running) {
        clearScreen();
        renderGame();
        printf("\nEnter control (W: Accelerate, S: Brake, A: Steer Left, D: Steer Right, G: Shift Gear, Q: Quit): ");
        if (fgets(input, sizeof(input), stdin)) {
            handleInput(input[0]);
            if (input[0] == 'Q' || input[0] == 'q') {
                running = false;
            }
        }
        updatePhysics();
        waitForFrame(FRAME_RATE);
    }
}