void WorkloadManager::generateReport() {
    cout << "Workload Report:" << endl;
    for (size_t i = 0; i < employees.size(); ++i) {
        const Employee& employee = employees[i];
        cout << "Employee: " << employee.getName() << ", Workload: " << employee.getCurrentWorkload() << " hours" << endl;
    }
}