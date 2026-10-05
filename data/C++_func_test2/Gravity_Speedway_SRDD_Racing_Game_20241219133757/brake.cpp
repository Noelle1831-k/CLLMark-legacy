void Vehicle::brake() {
    cout << "Braking vehicle..." << endl;
    speed -= acceleration;
    if (speed < 0) speed = 0;
}