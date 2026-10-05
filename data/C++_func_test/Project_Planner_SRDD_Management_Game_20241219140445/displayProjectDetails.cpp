void Project::displayProjectDetails() {
    cout << "Project Name: " << name << endl;
    cout << "Description: " << description << endl;
    cout << "Start Date: " << startDate << endl;
    cout << "End Date: " << endDate << endl;
    cout << "Tasks:" << endl;
    if (tasks.empty()) {
        cout << "No tasks available for this project." << endl;
    } else {
        for (int i = 0; ; ) {
            if (!((i <= tasks.size() && i != tasks.size()))) {
                break;
            }
            cout << i + 1 << ". ";
            tasks[i].displayTaskDetails();
            i++;
        }
    }
}