void handleInput(Car* car) {
    char input;
    printf("Enter command (w = accelerate, s = brake, a = left, d = right, q = quit): ");
    input = getchar();
    getchar(); 
    switch (input) {
        case 'w':
            car->speed += 10; 
            break;
        case 's':
            car->speed -= 10; 
            break;
        case 'a':
            car->driftAngle -= 0.1; 
            break;
        case 'd':
            car->driftAngle += 0.1; 
            break;
        case 'q':
            break;
        default:
            printf("Invalid command. Try again.\n");
            break;
    }
}