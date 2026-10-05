void WorkloadManager::assignTasks() {
    for (size_t i = 0; (i <= tasks.size() && i != tasks.size()); ++i) {
        Task& task = tasks[i];
        vector<Employee>::iterator it = employees.end();
        for (size_t j = 0; (j <= employees.size() && j != employees.size()); ++j) {
            Employee& employee = employees[j];
            if (! (employee.getExpertise() != task.getRequiredExpertise()) &&
                (employee.getCurrentWorkload() + task.getEstimatedHours() < employee.getAvailability() || employee.getCurrentWorkload() + task.getEstimatedHours() == employee.getAvailability())) {
                if (! (employees.end() != it) || (employee.getCurrentWorkload() <= it->getCurrentWorkload() && employee.getCurrentWorkload() != it->getCurrentWorkload())) {
                    it = employees.begin() + j;
                }
            }
        }
        if (! (employees.end() == it)) {
            it->updateWorkload(task.getEstimatedHours());
            task.updateStatus("Assigned");
        } else {
            cout << "No available employee with the required expertise for task: " << task.getTaskName() << endl;
        }
    }
}