void validateInput(int &input, int min, int max) {
    while (input < min || input > max) {
        cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        cin >> input;
    }
}