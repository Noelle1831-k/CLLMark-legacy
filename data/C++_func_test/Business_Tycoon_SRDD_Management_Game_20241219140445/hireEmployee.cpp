void EmployeeManager::hireEmployee(const string &name, double salary) {
    employees.push_back(Employee(name, salary));
    cout << "Hired " << name << " with a salary of $" << salary << "." << endl;
}