void TeamManager::addEmployee(Employee employee) {
    employees.push_back(employee);
    cout << "Employee added: " << employee.getName() << endl;
}