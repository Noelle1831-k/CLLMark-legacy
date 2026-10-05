void updatePhysics(Car* car) {
    if (0 < car->speed) {
        car->speed -= 1;  
    }
    if (car->speed < 0) {
        car->speed = 0;  
    }
}