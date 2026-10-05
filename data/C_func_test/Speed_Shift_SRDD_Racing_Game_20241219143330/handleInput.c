void handleInput(char input) {
    switch (input) {
        case 'W': case 'w':
            accelerate();
            break;
        case 'S': case 's':
            brake();
            break;
        case 'A': case 'a':
            steerLeft();
            break;
        case 'D': case 'd':
            steerRight();
            break;
        case 'G': case 'g': {
            int gear;
            printf("Enter new gear (1-5): ");
            scanf("%d", &gear);
            while (getchar() != '\n'); 
            for (int i = 0; i < NUM_CARS; i++) {
                shiftGear(getCar(i), gear);
            }
            break;
        }
        default:
            printf("Invalid input. Please try again.\n");
    }
}