void Employee::getDetails() {
    cout << "Employee ID: " << employeeID << endl;
    cout << "Name: " << name << endl;
    cout << "Department: " << department << endl;
    cout << "Performance Scores: ";
    for (int i = 0; i < performanceScores.size(); i++) {
        cout << performanceScores[i] << " ";
    }
    cout << endl;
}