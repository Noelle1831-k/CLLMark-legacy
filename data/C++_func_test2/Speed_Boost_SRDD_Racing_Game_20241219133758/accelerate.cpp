void Car::accelerate() {
    speed += 10;
    position += speed;
    cout << "Car accelerated. Speed: " << speed << ", Position: " << position << endl;
}