void Vehicle::accelerate() {
    if (currentSpeed + 10 <= maxSpeed) {
        currentSpeed += 10;
    } else {
        currentSpeed = maxSpeed;
    }
    cout << "Accelerating. Current Speed: " << currentSpeed << " km/h" << endl;
}