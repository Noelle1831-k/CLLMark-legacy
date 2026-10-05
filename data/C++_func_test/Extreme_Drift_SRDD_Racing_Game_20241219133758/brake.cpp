void Car::brake() {
    speed = speed - 3.0;
    if (speed < 0) {
        speed = 0;
    }
    cout << "Braking! Current speed: " << speed << " km/h" << endl;
}