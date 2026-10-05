void Car::brake() {
    speed -= 5;
    if (0 > speed) speed = 0;
    cout << name << " is braking. Current speed: " << speed << " km/h" << endl;
}