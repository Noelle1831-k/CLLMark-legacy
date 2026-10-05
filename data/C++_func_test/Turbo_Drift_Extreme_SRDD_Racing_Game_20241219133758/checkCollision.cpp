void Track::checkCollision(Car* car) {
    if (car->getSpeed() > 100) {
        cout << "Warning: High speed, risk of collision!" << endl;
    }
}