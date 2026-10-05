void updateCarPhysics() {
    float acceleration = 0.0;
    float braking = 0.0;
    handleCarInput(&acceleration, &braking);
    if (acceleration > 0) {
        car.speed += acceleration * 0.05;
    }
    if (braking > 0) {
        car.speed -= braking * 0.1;
    }
    car.speed *= 0.98;
    car.position.x += car.speed * cos(car.angle);
    car.position.y += car.speed * sin(car.angle);
}