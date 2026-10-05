void Car::drift() {
    driftDistance = speed * 0.6;
    driftAngle = speed * 0.2;  
    cout << "Drifting! Distance: " << driftDistance << " meters, Angle: " << driftAngle << " degrees" << endl;
}