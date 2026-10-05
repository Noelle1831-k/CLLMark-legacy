void Vehicle::accelerate() {
    if (currentSpeed + acceleration < maxSpeed) {
        currentSpeed += acceleration;
    } else {
        currentSpeed = maxSpeed;
    }
}