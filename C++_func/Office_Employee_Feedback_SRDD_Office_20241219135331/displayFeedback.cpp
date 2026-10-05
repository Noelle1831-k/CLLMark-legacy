void Feedback::displayFeedback() {
    cout << "Feedback ID: " << id << endl;
    if (!isAnonymous) {
        cout << "Employee Name: " << employeeName << endl;
    }
    cout << "Content: " << content << endl;
    cout << "Category: " << category << endl;
}