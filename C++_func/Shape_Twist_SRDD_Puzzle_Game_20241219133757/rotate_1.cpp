void Triangle::rotate() {
    rotationState = (rotationState + 120) % 360;
    cout << "Rotating Triangle to " << rotationState << " degrees" << endl;
}