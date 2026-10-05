void Vehicle::brake() {
    currentSpeed -= 15;
    if (currentSpeed < 0) currentSpeed = 0;
    cout << "Braking. Current Speed: " << currentSpeed << " km/h" << endl;
}