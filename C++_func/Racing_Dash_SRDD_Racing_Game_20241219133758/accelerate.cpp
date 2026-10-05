void Car::accelerate() {
    speed += acceleration;
    cout << model << " accelerating. Current speed: " << speed << " km/h" << endl;
}