void FeedbackSystem::addEmployee(int id, string name) {
    Employee newEmployee(id, name);
    employees.push_back(newEmployee);
}