double UserInterface::getUserInput() {
    double tempo;
    cout << "Enter desired tempo percentage: ";
    cin >> tempo;
    if (cin.fail() || tempo <= 0) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        throw invalid_argument("Invalid input. Please enter a positive number.");
    }
    return tempo;
}