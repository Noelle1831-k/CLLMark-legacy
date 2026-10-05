void Event::createEvent() {
    cout << "Enter Event Title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter Description: ";
    getline(cin, description);
    cout << "Enter Date (YYYY-MM-DD): ";
    getline(cin, date);
    cout << "Enter Location: ";
    getline(cin, location);
    cout << "Event created successfully! Event ID is " << eventID << endl;
}