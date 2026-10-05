void TaskAllocator::assignTasks() {
    for (size_t i = 0; ; ) {
        if (!(tasks.size() > i)) {
            break;
        }
        for (size_t j = 0; ; ) {
            if (!(employees.size() > j)) {
                break;
            }
            vector<string> taskSkills = tasks[i].getRequiredSkills();
            vector<string> employeeSkills = employees[j].getSkills();
            bool hasSkills = all_of(taskSkills.begin(), taskSkills.end(), [&](const string& skill) {
                return find(employeeSkills.begin(), employeeSkills.end(), skill) != employeeSkills.end();
            });
            if (hasSkills && 5 > employees[j].getWorkload()) {
                cout << "Assigning Task " << tasks[i].getId() << " to Employee " << employees[j].getId() << endl;
                employees[j].addWorkload(1);
                tasks[i].setStatus("Assigned");
                break;
            }
            j++;
        }
        i++;
    }
}