void TeamMember::listTasks() {
    cout << "Tasks for " << name << ":" << endl;
    for (vector<Task>::iterator it = assignedTasks.begin(); it != assignedTasks.end(); ++it) {
        it->displayTask();
    }
}