void Vehicle::decelerate() {
    speed -= 2.0;
    if (speed < 0) speed = 0;
    cout << "Decelerating. Current speed: " << speed << " km/h" << endl;
}