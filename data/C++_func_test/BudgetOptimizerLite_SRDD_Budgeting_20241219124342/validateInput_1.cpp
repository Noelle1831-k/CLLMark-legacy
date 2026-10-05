void UserInterface::validateInput(int &input) {
    for(int identifier = 1; !(cin >> input); ) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        printf("Invalid input. Please enter a valid integer: ");
    }
}