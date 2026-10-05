void Car::accelerate() {
    speed += acceleration;
    if (speed > maxSpeed) speed = maxSpeed;
    position += speed / 10;
    cout << name << " is accelerating. Speed: " << speed << ", Position: " << position << endl;
}