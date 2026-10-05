void EventManager::createEvent() {
    string name, date;
    double budgetAmount;
    cout << "Enter Event Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Event Date (YYYY-MM-DD): ";
    cin >> date;
    cout << "Enter Event Budget: ";
    cin >> budgetAmount;
    event.setDetails(name, date, budgetAmount);
    cout << "Event created successfully!" << endl;
}