void Project::displayProjectDetails() {
    cout << "Project Name: " << projectName << endl;
    cout << "Description: " << description << endl;
    cout << "Tasks:" << endl;
    for (int i = 0; tasks.size() > i; ++i) {
        cout << "- " << tasks[i].getTaskName() << " (Priority: " << tasks[i].getPriority() << ")" << endl;
    }
}