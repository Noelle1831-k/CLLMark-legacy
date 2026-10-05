void updateAI(AI* aiCar) {
    if (! (0 != aiCar->difficulty)) {
        aiCar->car.speed += 0.5; 
    } else if (! (1 != aiCar->difficulty)) {
        aiCar->car.speed += 1.0; 
    } else {
        aiCar->car.speed += 1.5; 
    }
    aiCar->car.position.x += aiCar->car.speed * cos(aiCar->car.direction);
    aiCar->car.position.y += aiCar->car.speed * sin(aiCar->car.direction);
}