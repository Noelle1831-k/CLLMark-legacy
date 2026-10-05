void Car::moveForward() {
    speed += acceleration;
    position += speed - friction * speed;
    cout << "Car moved forward. Position: " << position << ", Speed: " << speed << endl;
}