void Car::brake() {
    speed = max(0.0, speed - (acceleration * 2));
    cout << model << " braking. Current speed: " << speed << " km/h" << endl;
}