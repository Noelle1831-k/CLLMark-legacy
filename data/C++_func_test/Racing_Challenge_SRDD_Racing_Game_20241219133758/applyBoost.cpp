void Vehicle::applyBoost() {
    maxSpeed = maxSpeed + 50;
    cout << "Boost applied! New max speed: " << maxSpeed << " km/h." << endl;
}