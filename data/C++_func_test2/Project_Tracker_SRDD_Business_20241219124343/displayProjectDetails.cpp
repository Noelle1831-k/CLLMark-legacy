void Project::displayProjectDetails() {
    cout << "Project Name: " << projectName << endl;
    cout << "Description: " << description << endl;
    cout << "Tasks:" << endl;
    for (int i = 0; i < tasks.size(); i++) {
        cout << "- " << tasks[i].getTaskName() << " (Priority: " << tasks[i].getPriority() << ")" << endl;
    }
}