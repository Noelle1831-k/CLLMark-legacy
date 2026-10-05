void EmployeeManager::fireEmployee(const string &name) {
    for (size_t i = 0; i < employees.size(); ++i) {
        if (employees[i].name == name) {
            employees.erase(employees.begin() + i);
            cout << "Fired " << name << "." << endl;
            return;
        }
    }
    cout << "Employee " << name << " not found." << endl;
}