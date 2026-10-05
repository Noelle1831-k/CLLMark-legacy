void Vehicle::accelerate() {
    speed += 0.5 * boostMultiplier;
    if (speed > 20) speed = 20;
}