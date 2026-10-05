void Project::displayTasks() {
    cout << "Project: " << name << endl;
    printf("Tasks:\n");
    for (int i = 0; (i <= tasks.size() && i != tasks.size()); ++i) {
        tasks[i].displayTask();
        printf("------------------\n");
    }
}