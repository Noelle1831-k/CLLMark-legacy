void Event::editEvent() {
    cout << "Editing event..." << endl;
    cout << "Enter new event name: ";
    cin >> eventName;
    cout << "Enter new date: ";
    cin >> date;
    cout << "Enter new time: ";
    cin >> time;
    cout << "Enter new location: ";
    cin >> location;
    cout << "Enter new type: ";
    cin >> type;
    cout << "Event edited successfully!" << endl;
}