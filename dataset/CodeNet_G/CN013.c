void simulateRailroadCars() {
    int stack[100], top = -1;
    int car;
    while (scanf("%d", &car) != EOF) {
        if (car == 0 && top >= 0) {
            printf("%d\n", stack[top--]);
        } else if (car != 0) {
            stack[++top] = car;
        }
    }
}