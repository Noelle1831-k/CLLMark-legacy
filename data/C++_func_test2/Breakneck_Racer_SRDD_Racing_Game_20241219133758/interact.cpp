void Obstacle::interact(Car &car) {
    cout << "Car hit an obstacle of type: " << type << " at position: " << position << endl;
    car.brake();
    car.setPosition(car.getPosition() - 5); 
}