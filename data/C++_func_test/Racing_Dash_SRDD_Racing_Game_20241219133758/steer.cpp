void Car::steer(int direction) {
    if (direction > 0) {
        cout << model << " steering right." << endl;
    } else if (direction < 0) {
        cout << model << " steering left." << endl;
    }
}