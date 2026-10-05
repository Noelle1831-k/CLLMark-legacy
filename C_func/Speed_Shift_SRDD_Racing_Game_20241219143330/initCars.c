void initCars() {
    for (int i = 0; i < NUM_CARS; i++) {
        cars[i].id = i;
        cars[i].currentSpeed = 0;
        cars[i].maxSpeed = 200 + rand() % 50; 
        cars[i].gear = 1;
        cars[i].acceleration = 5.0;
        cars[i].deceleration = 2.0;
        cars[i].position.x = i * 10;
        cars[i].position.y = 0;
    }
}