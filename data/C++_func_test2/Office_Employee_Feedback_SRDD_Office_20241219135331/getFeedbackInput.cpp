Feedback UserInterface::getFeedbackInput() {
    int id;
    string employeeName;
    string content;
    string category;
    bool isAnonymous;
    cout << "Enter Feedback ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Employee Name (leave blank for anonymous): ";
    getline(cin, employeeName);
    cout << "Enter Feedback Content: ";
    getline(cin, content);
    cout << "Enter Feedback Category: ";
    getline(cin, category);
    cout << "Is this feedback anonymous? (1 for Yes, 0 for No): ";
    cin >> isAnonymous;
    if (employeeName.empty()) {
        isAnonymous = true;
    }
    return Feedback(id, employeeName, content, category, isAnonymous);
}