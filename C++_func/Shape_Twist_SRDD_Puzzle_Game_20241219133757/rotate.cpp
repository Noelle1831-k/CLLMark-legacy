void Square::rotate() {
    rotationState = (rotationState + 90) % 360;
    cout << "Rotating Square to " << rotationState << " degrees" << endl;
}