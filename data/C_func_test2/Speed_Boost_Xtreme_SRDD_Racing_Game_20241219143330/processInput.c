void processInput(GameEngine* engine) {
    printf("[InputHandler] Processing input...\n");
    char input;
    printf("Enter command (w: accelerate, s: brake, b: boost, q: quit): ");
    scanf(" %c", &input);
    switch (input) {
        case 'w':
            accelerate(engine->car);
            break;
        case 's':
            brake(engine->car);
            break;
        case 'b':
            boost(engine->car);
            break;
        case 'q':
            engine->isRunning = false;
            break;
        default:
            printf("[InputHandler] Invalid input!\n");
    }
}