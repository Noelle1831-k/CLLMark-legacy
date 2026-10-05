void InputHandler::processInput(Car &car) {
    char input;
    cout << "Enter 'w' to accelerate, 's' to brake, 'g' to shift gear: ";
    cin >> input;
    if (input == 'w') car.accelerate();
    else if (input == 's') car.brake();
    else if (input == 'g') {
        int newGear;
        cout << "Enter new gear: ";
        cin >> newGear;
        car.shiftGear(newGear);
    }
}