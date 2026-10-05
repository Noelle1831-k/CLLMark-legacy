void Car::handleInput() {
    char input;
    cout << "Enter 'w' to accelerate, 's' to brake, 'a' to turn left, 'd' to turn right: ";
    cin >> input;
    switch (input) {
    case 'w': accelerate(); break;
    case 's': brake(); break;
    case 'a': turnLeft(); break;
    case 'd': turnRight(); break;
    }
}