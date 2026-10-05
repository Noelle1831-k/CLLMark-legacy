void Car::accelerate() {
    speed += 5.0;
    if (speed > 300.0f) {
        speed = 300.0f; 
    }
    cout << "Accelerating! Current speed: " << speed << " km/h" << endl;
}