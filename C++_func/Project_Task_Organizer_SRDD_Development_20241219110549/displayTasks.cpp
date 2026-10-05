void Project::displayTasks() {
    cout << "Project: " << name << endl;
    cout << "Tasks:\n";
    for (int i = 0; i < tasks.size(); ++i) {
        tasks[i].displayTask();
        cout << "------------------\n";
    }
}