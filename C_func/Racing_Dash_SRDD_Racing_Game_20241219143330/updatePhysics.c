void updatePhysics(Car* car) {
    if (car->speed > 0) {
        car->speed -= 1;  
    }
    if (car->speed < 0) {
        car->speed = 0;  
    }
}