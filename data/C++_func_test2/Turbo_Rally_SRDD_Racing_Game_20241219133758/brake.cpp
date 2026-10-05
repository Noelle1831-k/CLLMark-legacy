void Vehicle::brake() {
    if (currentSpeed > 0) {
        currentSpeed -= handling;
    } else {
        currentSpeed = 0;
    }
}