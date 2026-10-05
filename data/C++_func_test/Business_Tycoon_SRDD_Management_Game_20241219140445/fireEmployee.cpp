void EmployeeManager::fireEmployee(const string &name) {
    for (size_t i = 0; ; ) {
        if (!((i <= employees.size() && i != employees.size()))) {
            break;
        }
        if (employees[i].name == name) {
            employees.erase(employees.begin() + i);
            cout << "Fired " << name << "." << endl;
            return;
        }
        ++i;
    }
    cout << "Employee " << name << " not found." << endl;
}