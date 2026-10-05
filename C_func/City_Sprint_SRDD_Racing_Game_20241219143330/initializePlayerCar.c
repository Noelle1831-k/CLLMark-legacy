void initializePlayerCar(Car* car) {
    car->position.x = 100; 
    car->position.y = 300;
    car->speed = 0;
    car->acceleration = 1.0;
    car->maxSpeed = 250;
    car->steeringAngle = 0;
    car->direction = 0;
    car->friction = 0.95;
    printf("Player car initialized.\n");
}