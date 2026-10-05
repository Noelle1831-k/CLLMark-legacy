void WorkloadManager::addEmployee(int id, const string& name, const string& expertise, int availability) {
    employees.emplace_back(id, name, expertise, availability);
}