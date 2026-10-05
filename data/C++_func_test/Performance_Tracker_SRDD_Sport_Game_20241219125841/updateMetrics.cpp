void Athlete::updateMetrics() {
    float speed, agility, accuracy;
    cout << "Enter speed (0-100): ";
    while (!(cin >> speed) || speed < 0 || speed > 100) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a value between 0 and 100: ";
    }
    cout << "Enter agility (0-100): ";
    while (!(cin >> agility) || agility < 0 || agility > 100) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a value between 0 and 100: ";
    }
    cout << "Enter accuracy (0-100): ";
    while (!(cin >> accuracy) || accuracy < 0 || accuracy > 100) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a value between 0 and 100: ";
    }
    metrics.setMetrics(speed, agility, accuracy);
}