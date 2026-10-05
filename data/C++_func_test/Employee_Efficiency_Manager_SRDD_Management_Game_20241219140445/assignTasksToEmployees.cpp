void TeamManager::assignTasksToEmployees() {
    for (int i = 0; i < tasks.size(); i++) {
        employees[i % employees.size()].assignTask(tasks[i]);
    }
}