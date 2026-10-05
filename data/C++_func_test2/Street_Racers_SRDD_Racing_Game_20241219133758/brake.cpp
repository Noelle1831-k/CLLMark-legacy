void Car::brake() {
    speed -= 5;
    if (speed < 0) speed = 0;
    cout << name << " is braking. Current speed: " << speed << " km/h" << endl;
}