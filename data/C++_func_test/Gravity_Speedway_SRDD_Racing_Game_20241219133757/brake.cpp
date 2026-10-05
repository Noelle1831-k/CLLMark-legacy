void Vehicle::brake() {
    cout << "Braking vehicle..." << endl;
    speed = speed - acceleration;
    if (speed < 0) speed = 0;
}