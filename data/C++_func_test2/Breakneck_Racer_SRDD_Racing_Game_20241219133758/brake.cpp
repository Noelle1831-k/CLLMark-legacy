void Car::brake() {
    speed -= acceleration / 2;
    if (speed < 0) speed = 0;
    cout << name << " is braking. Speed: " << speed << endl;
}