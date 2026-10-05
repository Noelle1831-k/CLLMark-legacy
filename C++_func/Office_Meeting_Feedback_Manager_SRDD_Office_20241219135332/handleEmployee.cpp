void handleEmployee(vector<Meeting> &meetings, vector<Employee> &employees) {
    int empId;
    cout << "Enter your Employee ID: ";
    cin >> empId;
    Employee *currentEmployee = nullptr;
    for (auto &employee : employees) {
        if (employee.getId() == empId) {
            currentEmployee = &employee;
            break;
        }
    }
    if (!currentEmployee) {
        cout << "Employee not found!" << endl;
        return;
    }
    cout << "Available Meetings:" << endl;
    for (size_t i = 0; i < meetings.size(); i++) {
        cout << i + 1 << ". " << meetings[i].getTitle() << endl;
    }
    int meetingChoice;
    cout << "Select a meeting to provide feedback for: ";
    cin >> meetingChoice;
    if (meetingChoice < 1 || meetingChoice > meetings.size()) {
        cout << "Invalid meeting choice!" << endl;
        return;
    }
    Meeting &selectedMeeting = meetings[meetingChoice - 1];
    string feedbackText;
    cout << "Enter your feedback: ";
    cin.ignore(); 
    getline(cin, feedbackText);
    Feedback feedback(currentEmployee->getName(), feedbackText);
    selectedMeeting.addFeedback(feedback);
    cout << "Feedback submitted successfully!" << endl;
}