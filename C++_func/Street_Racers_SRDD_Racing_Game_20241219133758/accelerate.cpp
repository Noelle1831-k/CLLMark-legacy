void Car::accelerate() {
    if (speed < maxSpeed) {
        acceleration += 1.5;
        speed += acceleration;
    }
    cout << name << " is accelerating. Current speed: " << speed << " km/h" << endl;
}