void Athlete::inputDetails() {
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your sport: ";
    getline(cin, sport);
    cout << "Enter your training goal: ";
    getline(cin, goal);
}