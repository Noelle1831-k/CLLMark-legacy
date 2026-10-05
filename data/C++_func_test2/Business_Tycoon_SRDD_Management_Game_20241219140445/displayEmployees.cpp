void EmployeeManager::displayEmployees() {
    cout << "Employees:" << endl;
    for (size_t i = 0; i < employees.size(); ++i) {
        cout << employees[i].name << " - $" << employees[i].salary << endl;
    }
}