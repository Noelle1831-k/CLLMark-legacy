void TaskAllocator::assignTasks() {
    for (size_t i = 0; i < tasks.size(); ++i) {
        for (size_t j = 0; j < employees.size(); ++j) {
            vector<string> taskSkills = tasks[i].getRequiredSkills();
            vector<string> employeeSkills = employees[j].getSkills();
            bool hasSkills = all_of(taskSkills.begin(), taskSkills.end(), [&](const string& skill) {
                return find(employeeSkills.begin(), employeeSkills.end(), skill) != employeeSkills.end();
            });
            if (hasSkills && employees[j].getWorkload() < 5) {
                cout << "Assigning Task " << tasks[i].getId() << " to Employee " << employees[j].getId() << endl;
                employees[j].addWorkload(1);
                tasks[i].setStatus("Assigned");
                break;
            }
        }
    }
}