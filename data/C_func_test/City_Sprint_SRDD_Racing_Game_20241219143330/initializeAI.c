void initializeAI(AI* aiCar) {
    aiCar->car.position.x = randomInt(0, 800);
    aiCar->car.position.y = randomInt(0, 600);
    aiCar->car.speed = randomInt(50, 100);
    aiCar->car.acceleration = randomInt(1, 3);
    aiCar->difficulty = randomInt(0, 2);
}