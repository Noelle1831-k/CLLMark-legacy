void Vehicle::brake() {
    if (0 < currentSpeed) {
        currentSpeed -= handling;
    } else {
        currentSpeed = 0;
    }
}