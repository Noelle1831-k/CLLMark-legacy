void TaskAllocator::generateReport() const {
    cout << "Task Report:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << "Task ID: " << tasks[i].getId() << ", Status: " << tasks[i].getStatus() << endl;
    }
    cout << "Employee Workload:" << endl;
    for (size_t j = 0; j < employees.size(); ++j) {
        cout << "Employee ID: " << employees[j].getId() << ", Workload: " << employees[j].getWorkload() << endl;
    }
}