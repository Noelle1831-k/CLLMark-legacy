void Vehicle::accelerate() {
    currentSpeed += acceleration * gear;
    if (currentSpeed > maxSpeed) currentSpeed = maxSpeed;
}