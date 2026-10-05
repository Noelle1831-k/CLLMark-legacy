void Car::brake() {
    speed -= 5;
    if (speed < 0) speed = 0;
    cout << "Braking. Speed: " << speed << endl;
}